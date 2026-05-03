#include <array>
#include <iostream>
#include <string>
#include <vector>

// my naïve solution
// class Solution {
// public:
//   bool rotateString(std::string s, std::string goal) {
//     if (s.size() != goal.size())
//       return false;
//     const size_t n = s.size();
//     for (size_t i = 0; i < n; i++) {
//       size_t j;
//       for (j = 0; j < n && j < n && s[(j + i) % n] == goal[j]; j++)
//         ;
//       if (j == n) {
//         return true;
//       }
//     }
//     return false;
//   }
// };

// didn't work. Too lossy :(
// const size_t ALPHABET_SIZE = 'z' - 'a' + 1;
//
// class Solution {
//   std::array<std::vector<char>, ALPHABET_SIZE> followSets(std::string s) {
//     std::array<std::vector<char>, ALPHABET_SIZE> follows;
//     const size_t n = s.size();
//     // could also be written as follows[s[i] - 'a'].push_back(s[(i + 1) %
//     // s.size()]);
//     for (size_t i = 0; i + 1 < n; i++) {
//       follows[s[i] - 'a'].push_back(s[i + 1]);
//     }
//     follows[s[n - 1] - 'a'].push_back(s[0]);
//     std::cout << "follow set: ";
//     for (size_t i = 0; i < ALPHABET_SIZE; i++) {
//       if (follows[i].empty())
//         continue;
//       std::cout << "\n\tchar " << (char)('a' + i) << ": ";
//       for (auto c : follows[i]) {
//         std::cout << c << " ";
//       }
//     }
//     std::cout << std::endl;
//     return follows;
//   }
//
// public:
//   bool rotateString(std::string s, std::string goal) {
//     return followSets(s) == followSets(goal);
//   }
// };

// even better ig?
// class Solution {
// public:
//   bool rotateString(std::string s, std::string goal) {
//     return s.size() == goal.size() && (s + s).find(goal) !=
//     std::string::npos;
//   }
// };

// MINE!!! thanks Knuth
class KmpSearch {
  std::string pattern;
  std::vector<size_t> lps;

public:
  KmpSearch(const std::string &pattern) : pattern(std::move(pattern)) {
    lps = std::vector<size_t>(pattern.size(), 0);

    size_t j = 0;
    for (size_t i = 1; i < pattern.size(); i++) {
      while (j > 0 && pattern[j] != pattern[i]) {
        j = lps[j - 1];
      }
      lps[i] = (j += pattern[j] == pattern[i]);
    }
  }

  bool contained(const std::string &s) {
    size_t s_i = 0, p_i = 0, n = s.size();
    while (s_i < n * 2 && p_i < pattern.size()) {
      if (s[s_i % n] == pattern[p_i]) {
        s_i++;
        p_i++;
      } else {
        s_i += !p_i;
        p_i = lps[p_i > 0 ? p_i - 1 : 0];
      }
    }

    return p_i == pattern.size();
  }
};

class Solution {
public:
  bool rotateString(std::string s, std::string goal) {
    KmpSearch kmp(goal);
    return s.size() == goal.size() && kmp.contained(s);
  }
};
