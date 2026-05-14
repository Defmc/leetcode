#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    std::size_t lo = 0, hi = height.size() - 1, maxAreaFound = 0;

    auto getArea = [&](const size_t loIdx, const size_t hiIdx) {
      const int maxCol = std::min(height[loIdx], height[hiIdx]);
      return (hiIdx - loIdx) * maxCol;
    };

    while (lo < hi) {
      const size_t area = getArea(lo, hi);
      if (area > maxAreaFound) {
        maxAreaFound = area;
      }
      if (height[lo] < height[hi]) {
        lo++;
      } else {
        hi--;
      }
    }

    return maxAreaFound;
  }
};
