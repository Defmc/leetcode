#include <string>
#include <vector>

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
    size_t s_i = 0, p_i = 0;
    while (s_i < s.size() && p_i < pattern.size()) {
      if (s[s_i] == pattern[p_i]) {
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
