#include <cstdlib>
#include <vector>

class Solution {
public:
  std::vector<int> getSneakyNumbers(std::vector<int> &nums) {
    int first_sneaky = -1;
    const size_t nums_size = nums.size();

    for (size_t i = 0; i < nums_size; i++) {
      int n = nums[i] % nums_size;
      if (nums[n] >= nums_size) {
        if (first_sneaky == -1)
          first_sneaky = n;
        else
          return {first_sneaky, n};
      } else {
        nums[n] += nums_size;
      }
    }
    return {-1, -1};
  }
};
