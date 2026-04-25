#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    std::vector<std::vector<bool>> palins(s.size(),
                                          std::vector<bool>(s.size(), false));

    size_t maxBegin = 0, maxEnd = 0;

    for (size_t i = 0; i < s.size(); i++) {
      palins[i][i] = true;
    }

    for (size_t i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1]) {
        palins[i][i + 1] = true;
        if (maxEnd == 0) {
          maxBegin = i;
          maxEnd = i + 1;
        }
      }
    }

    for (size_t i = 0; i < s.size(); i++) {
        :w
    }

    return longestPalin;
  }
};
