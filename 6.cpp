#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    std::vector<std::string> rows(numRows);
    int p = 0, d = 1;
    for (size_t i = 0; i < s.size(); i++) {
      rows[p].push_back(s[i]);
      p += d;
      if (p + 1 > numRows) {
        d = -1;
        p = std::max(0, numRows - 2);
      } else if (p < 0) {
        d = 1;
        p = std::min(1, numRows - 1);
      }
    }
    std::string res;
    for (auto &str : rows) {
      res += str;
    }

    return res;
  }
};
