#include <climits>
class Solution {
public:
  int reverse(int x) {
    if (x < 0) {
      return x < -INT_MAX ? 0 : -reverse(-x);
    }
    int rev = 0;
    while (x > 0) {
      if (rev > INT_MAX / 10 || x > (INT_MAX - rev * 10)) {
        return 0;
      }
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return rev;
  }
};
