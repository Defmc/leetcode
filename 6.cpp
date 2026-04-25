#include <string>

using namespace std;

// worse cache behaviour than doing the pointer bouncing, but better in terms of
// allocation
class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    std::string res(s.size(), ' ');
    for (size_t row = 0; row < numRows; row++) {
      bool lastBigJump = false;
      for (size_t i = row; i < s.size();) {
        res[i] = s[i];
        i += ((row > 0 && lastBigJump) || row == numRows - 1)
                 ? 2 * row
                 : 2 * (numRows - 1 - row);
        lastBigJump = !lastBigJump;
      }
    }
    return res;
  }
};
