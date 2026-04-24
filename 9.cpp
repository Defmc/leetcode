class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    unsigned rev = 0, y = x;
    while (y) {
      rev = rev * 10 + y % 10;
      y /= 10;
    }
    return x == rev;
  }
};
