
// my lousy, first attempt... I liked it nonetheless
// struct hashFunction {
//   size_t operator()(const std::tuple<int, int, int> &x) const {
//     return std::get<0>(x) ^ std::get<1>(x) ^ std::get<2>(x);
//   }
// };
// class Solution {
// public:
//   std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
//     // xi + xj : (i, j)
//     std::unordered_map<int, std::vector<int>> firstSum;
//     int n = nums.size();
//     firstSum.reserve(n * n);
//
//     for (int i = 0; i < n; i++) {
//       for (int j = i + 1; j < n; j++) {
//         int sum = nums[i] + nums[j];
//         if (firstSum.find(sum) == firstSum.end()) {
//           firstSum[sum] = {i, j};
//         } else {
//           std::vector<int> &fs = firstSum[sum];
//           fs.push_back(i);
//           fs.push_back(j);
//         }
//       }
//     }
//
//     std::vector<std::vector<int>> triplets;
//     std::unordered_set<std::tuple<int, int, int>> present;
//
//     for (int i = 0; i < n; i++) {
//       int v = -nums[i];
//       if (firstSum.find(v) != firstSum.end()) {
//         std::vector<int> &fs = firstSum[v];
//         for (size_t vi = 0; vi + 1 < fs.size(); vi += 2) {
//           if (fs[vi] == i || fs[vi + 1] == i) {
//             continue;
//           }
//           int a = nums[fs[vi]], b = nums[fs[vi + 1]], c = nums[i];
//           if (b > c)
//             std::swap(b, c);
//           if (a > b)
//             std::swap(a, b);
//           std::tuple s{a, b, c};
//           if (present.find(s) != present.end())
//             continue;
//           triplets.push_back({a, b, c});
//           present.insert(s);
//         }
//       }
//     }
//     return triplets;
//   }
// };
//

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> triplets;
    size_t n = nums.size();
    for (size_t i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      size_t lo = i + 1, hi = n - 1;
      while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum == 0) {
          triplets.push_back({nums[i], nums[lo], nums[hi]});
          for (int old_nlo = nums[lo]; lo < hi && nums[lo] == old_nlo; lo++)
            ;
        } else if (sum > 0) {
          hi--;
        } else if (sum < 0) {
          lo++;
        }
      }
    }

    return triplets;
  }
};
