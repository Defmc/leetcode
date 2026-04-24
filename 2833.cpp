#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
  int furthestDistanceFromOrigin(string moves) {
    int underlines = 0, currPoint = 0;
    for (char c : moves) {
      switch (c) {
      case '_':
        underlines++;
        break;
      case 'L':
        currPoint--;
        break;
      case 'R':
        currPoint++;
        break;
      }
    }
    return std::abs(currPoint) + underlines;
  }
};
