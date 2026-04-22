#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> s;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (s.find(diff) != s.end()) {
        int j = s[diff];
        return std::vector<int>{j, i};
      }
      s[nums[i]] = i;
    }
    return vector<int>{-1, -1};
  }
};
