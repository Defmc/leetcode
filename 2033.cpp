#include <algorithm>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<std::vector<int>> &grid, int x) {
    size_t rows = grid.size(), cols = grid[0].size();
    std::vector<int> xFactors;
    xFactors.reserve(rows * cols);
    const int firstRem = grid[0][0] % x;

    for (auto &row : grid) {
      for (int n : row) {
        if (n % x != firstRem) {
          return -1;
        }
        xFactors.push_back(n / x);
      }
    }

    auto median = xFactors.begin() + xFactors.size() / 2;
    std::nth_element(xFactors.begin(), median, xFactors.end());
    int factorTarget = *median;
    int totalChanges = 0;
    for (auto n : xFactors) {
      totalChanges += std::abs(factorTarget - n);
    }
    return totalChanges;
  }
};
