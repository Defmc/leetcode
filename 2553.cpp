#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> separateDigits(std::vector<int> &nums) {
    const size_t n = nums.size();
    std::vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
      int currNum = nums[i];
      while (currNum > 0) {
        res.push_back(currNum % 10);
        currNum /= 10;
      }
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
