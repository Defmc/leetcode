#include <numeric>
#include <vector>

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
