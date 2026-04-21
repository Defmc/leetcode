#include <vector>

using namespace std;

class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    for (int offset = 0; offset < nums.size(); offset++) {
      if ((start + offset < nums.size() && nums[start + offset] == target) ||
          (start - offset >= 0 && nums[start - offset] == target))
        return offset;
    }
    return -1;
  }
};
