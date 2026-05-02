#include <cmath>
#include <vector>

enum State { INVALID, BAD, GOOD };

const State DIGITS[]{BAD,  BAD,  GOOD,    INVALID, INVALID,
                     GOOD, GOOD, INVALID, BAD,     GOOD};

class Solution {
public:
  int rotatedDigits(int n) {
    int goods = 0;

    std::vector<State> ns(n + 1, BAD);

    for (int i = 1; i <= n; i++) {
      int digit = i % 10, prefix = i / 10;
      if (ns[prefix] == State::INVALID) {
        ns[i] = State::INVALID;
        continue;
      }
      State s = (DIGITS[digit] == State::BAD) ? ns[prefix] : DIGITS[digit];
      if (s == State::GOOD) {
        goods++;
      }
      ns[i] = s;
    }

    return goods;
  }
};
