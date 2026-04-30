#include <cstdlib>
#include <vector>

class Solution {
public:
  std::vector<int> findDuplicates(std::vector<int> &nums) {
    std::vector<int> duplicates;
    for (size_t i = 0; i < nums.size(); i++) {
      int n = std::abs(nums[i]);
      if (nums[n - 1] < 0) {
        duplicates.push_back(n);
      } else {
        nums[n - 1] *= -1;
      }
    }
    return duplicates;
  }
};
