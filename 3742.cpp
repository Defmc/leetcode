#include <algorithm>
#include <vector>

class Solution {
public:
  int maxPathScore(std::vector<std::vector<int>> &grid, int k) {
    size_t m = grid.size(), n = grid[0].size();

    std::vector<std::vector<std::vector<int>>> dp(
        std::vector(m, std::vector(n, std::vector(k + 1, -1))));

    dp[0][0][0] = 0;
    for (size_t mi = 0; mi < m; mi++) {
      for (size_t ni = 0; ni < n; ni++) {
        for (size_t c = 0; c <= k; c++) {
          if (dp[mi][ni][c] == -1)
            continue;
          if (mi + 1 < m) {
            int cost = !(grid[mi + 1][ni] == 0);
            if (c + cost <= k) {
              dp[mi + 1][ni][c + cost] = std::max(
                  dp[mi][ni][c] + grid[mi + 1][ni], dp[mi + 1][ni][c + cost]);
            }
          }
          if (ni + 1 < n) {
            int cost = !(grid[mi][ni + 1] == 0);
            if (c + cost <= k) {
              dp[mi][ni + 1][c + cost] = std::max(
                  dp[mi][ni][c] + grid[mi][ni + 1], dp[mi][ni + 1][c + cost]);
            }
          }
        }
      }
    }

    auto &finals = dp[m - 1][n - 1];
    return *std::max_element(finals.begin(), finals.end());
  }
};
