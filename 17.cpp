#include <cmath>
#include <string>
#include <vector>

const std::string_view PHONE_NUMPAD[]{"",    "",    "abc",  "def", "ghi",
                                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> ret{""}, buff;
    buff.reserve(std::pow(4, digits.size()));
    ret.reserve(std::pow(4, digits.size()));

    for (auto c : digits) {
      buff.clear();
      for (auto phoneNum : PHONE_NUMPAD[c - '0']) {
        for (auto &s : ret) {
          buff.push_back(s + phoneNum);
        }
      }
      std::swap(buff, ret);
    }

    return ret;
  }
};
