#include <cassert>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    const size_t n = matrix.size();
    for (size_t corner = 0; corner < n / 2; corner++) {
      const size_t last = n - corner - 1;
      for (size_t offset = 0; offset < last - corner; offset++) {

        std::swap(matrix[corner][corner + offset],
                  matrix[last - offset][corner]);

        std::swap(matrix[last - offset][corner], matrix[last][last - offset]);

        std::swap(matrix[last][last - offset], matrix[corner + offset][last]);
      }
    }
  }
};
