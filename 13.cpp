#include <string>
#include <vector>
using namespace std;

class Solution {
  std::vector<int> numerals;

public:
  Solution() : numerals(26, -1) {
    numerals['I' - 'A'] = 1;
    numerals['V' - 'A'] = 5;
    numerals['X' - 'A'] = 10;
    numerals['L' - 'A'] = 50;
    numerals['C' - 'A'] = 100;
    numerals['D' - 'A'] = 500;
    numerals['M' - 'A'] = 1000;
  }

  int romanToInt(string s) {
    int n = 0;
    for (size_t i = 0; i < s.size(); i++) {
      int c = numerals[s[i] - 'A'];
      n += (i + 1 < s.size() && c < numerals[s[i + 1] - 'A'] ? -1 : 1) * c;
    }
    return n;
  }
};
