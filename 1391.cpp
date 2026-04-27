#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define LEFT {-1, 0}
#define RIGHT {1, 0}
#define UP {0, -1}
#define DOWN {0, 1}

const int CONNECTIONS[6][2][2]{{LEFT, RIGHT}, {UP, DOWN}, {LEFT, DOWN},
                               {RIGHT, DOWN}, {LEFT, UP}, {RIGHT, UP}};

class disjoint_set {
  std::vector<size_t> parent, size;

public:
  disjoint_set(const size_t n) : parent(n), size(n, 1) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  size_t find(const size_t v) {
    if (v != parent[v])
      parent[v] = find(parent[v]);
    return parent[v];
  }

  bool unite(const size_t a, const size_t b) {
    size_t fs_a = find(a), fs_b = find(b);
    if (fs_a == fs_b)
      return false;
    if (size[fs_a] < size[fs_b])
      std::swap(fs_a, fs_b);
    parent[fs_b] = fs_a;
    size[fs_a] += size[fs_b];
    return true;
  }
};

class Solution {

public:
  bool hasValidPath(vector<vector<int>> &grid) {
    size_t m = grid.size(), n = grid[0].size();

    disjoint_set dsu(m * n);
    for (size_t y = 0; y < m; y++) {
      for (size_t x = 0; x < n; x++) {
        int curr_t = grid[y][x] - 1;
        for (auto &p : CONNECTIONS[curr_t]) {
          if (x + p[0] < n && y + p[1] < m) {
            int neighbour_t = grid[y + p[1]][x + p[0]] - 1;
            for (auto &neighbour_p : CONNECTIONS[neighbour_t]) {
              if (p[0] + neighbour_p[0] == 0 && p[1] + neighbour_p[1] == 0) {
                dsu.unite(y * n + x, (y + p[1]) * n + x + p[0]);
              }
            }
          }
        }
      }
    }

    return dsu.find(0) == dsu.find(grid.size() * grid[0].size() - 1);
  }
};
