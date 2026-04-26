#include <numeric>
#include <vector>

using namespace std;
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
      return true;
    if (size[fs_a] < size[fs_b])
      std::swap(fs_a, fs_b);
    parent[fs_b] = fs_a;
    size[fs_a] += size[fs_b];
    return false;
  }
};

class Solution {
public:
  bool containsCycle(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    disjoint_set dsu(m * n);

    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        char c = grid[i][j];
        bool found = false;
        if (i + 1 < m && grid[i + 1][j] == c)
          found |= dsu.unite(i * n + j, (i + 1) * n + j);
        if (j + 1 < n && grid[i][j + 1] == c)
          found |= dsu.unite(i * n + j, i * n + j + 1);
        if (found)
          return true;
      }
    }
    return false;
  }
};
