#include <deque>
#include <vector>

class Solution {
public:
  std::vector<std::vector<char>>
  rotateTheBox(const std::vector<std::vector<char>> &boxGrid) {
    const size_t cols = boxGrid[0].size(), rows = boxGrid.size();
    std::vector<std::vector<char>> rotated(boxGrid[0].size(),
                                           std::vector<char>(boxGrid.size()));

    for (size_t row = 0; row < rows; row++) {
      for (size_t col = 0; col < cols; col++) {
        // A^-1 with inverted rows
        rotated[col][rows - 1 - row] = boxGrid[row][col];
      }
    }

    std::deque<size_t> freeSlots;
    for (size_t col = 0; col < rows; col++) {
      freeSlots.clear();
      for (int row = cols - 1; row >= 0; row--) {
        switch (rotated[row][col]) {
        case '#':
          if (freeSlots.empty()) {
            break;
          }
          {
            size_t slot = freeSlots.front();
            rotated[slot][col] = '#';
            rotated[row][col] = '.';
          }
          freeSlots.pop_front();
        case '.':
          freeSlots.push_back(row);
          break;
        case '*':
          freeSlots.clear();
          break;
        }
      }
    }

    return rotated;
  }
};
