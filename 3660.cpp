#include <climits>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> maxValue(std::vector<int> &nums) {
    const size_t n = nums.size();
    std::vector<int> ans(n, 0);

    using Item = std::pair<int, size_t>;
    std::vector<Item> prevMax(n);

    Item prev = {INT_MIN, -1};

    for (size_t i = 0; i < n; i++) {
      if (nums[i] > prev.first) {
        prev = {nums[i], i};
      }
      prevMax[i] = prev;
    }

    auto proc = [&](auto &self, size_t r, int minr, int maxr) -> void {
      auto [max, pivot] = prevMax[r];
      int currMax = max <= minr ? max : maxr;

      int nextMin = std::min(max, minr);
      for (size_t i = pivot; i <= r; i++) {
        ans[i] = currMax;
        nextMin = std::min(nextMin, nums[i]);
      }

      if (pivot == 0) {
        return;
      }
      self(self, --pivot, nextMin, currMax);
    };

    proc(proc, n - 1, INT_MAX, 0);

    return ans;
  }
};
