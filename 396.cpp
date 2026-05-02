#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxRotateFunction(std::vector<int> &nums) {
    int sum = 0, f0 = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      f0 += i * nums[i];
      sum += nums[i];
    }

    int fk = f0;
    int maxRotations = f0;
    for (size_t k = 1; k < n; k++) {
      fk += sum - n * nums[n - k];
      maxRotations = std::max(maxRotations, fk);
    }

    return maxRotations;
  }
};
