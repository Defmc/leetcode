#include <functional>
#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    std::string buff;
    buff.reserve(2 * n);

    std::function<void(size_t, size_t)> paren = [&](size_t l, size_t r) {
      if (l + r == 2 * n) {
        ans.push_back(buff);
        return;
      }
      if (l < n) {
        buff.push_back('(');
        paren(l + 1, r);
        buff.pop_back();
      }
      if (l > r) {
        buff.push_back(')');
        paren(l, r + 1);
        buff.pop_back();
      }
    };

    paren(0, 0);
    return ans;
  }
};
