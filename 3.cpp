#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int longestSub = 0, currSub = 0;
    std::array<int, 127> places;
    places.fill(-1);
    for (size_t i = 0; i < s.size(); i++) {
      if (places[s[i]] >= (int)i - currSub) {
        currSub = i - places[s[i]];
      } else {
        longestSub = std::max(longestSub, ++currSub);
      }
      places[s[i]] = i;
    }

    return longestSub;
  }
};
