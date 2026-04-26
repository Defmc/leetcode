#include <cstdint>
#include <vector>

using namespace std;

class Solution {
  enum state : uint8_t { UNVISITED, PROCESSING, DONE };
  using coord = std::pair<int, int>;

  bool dfs_explore(const vector<vector<char>> &grid,
                   std::vector<std::vector<state>> &visited, const coord curr,
                   const coord parent, const char ch) {

    if (curr.first >= visited.size() || curr.second >= visited[0].size() ||
        grid[curr.first][curr.second] != ch)
      return false;
    state *my_state = &visited[curr.first][curr.second];
    if (*my_state != UNVISITED)
      return *my_state == PROCESSING;

    *my_state = PROCESSING;

    const coord d[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto [d0, d1] : d) {
      coord c{curr.first + d0, curr.second + d1};
      if (c != parent && dfs_explore(grid, visited, c, curr, ch))
        return true;
    }
    *my_state = DONE;
    return false;
  }

public:
  bool containsCycle(vector<vector<char>> &grid) {
    std::vector<std::vector<state>> visited(
        grid.size(), std::vector(grid[0].size(), UNVISITED));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        coord begin{i, j};
        if (dfs_explore(grid, visited, begin, begin, grid[i][j])) {
          return true;
        }
      }
    }

    return false;
  }
};
