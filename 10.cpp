#include <cstring>
#include <string>

using namespace std;

class Solution {
  int memo[21][21];

  bool localMatch(const string &s, const string &p, const int is,
                  const int ip) {
    if (ip >= p.size())
      return is >= s.size();
    if (memo[is][ip] != -1)
      return memo[is][ip];

    bool isValid = is < s.size() && (s[is] == p[ip] || p[ip] == '.');

    if (ip + 1 < p.size() && p[ip + 1] == '*')
      return memo[is][ip] = localMatch(s, p, is, ip + 2) ||
                            (isValid && localMatch(s, p, is + 1, ip));

    return memo[is][ip] = isValid && localMatch(s, p, is + 1, ip + 1);
  }

public:
  bool isMatch(string s, string p) {
    memset(memo, -1, sizeof(memo));
    return localMatch(s, p, 0, 0);
  }
};
