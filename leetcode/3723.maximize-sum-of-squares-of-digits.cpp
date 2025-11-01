#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string maxSumOfSquares(int num, int sum) {
    if (sum > 9 * num) {
      return {};
    }
    string ans;
    for (int i = 0; i < num; ++i) {
      int toPush = min(sum, 9);
      ans.push_back(toPush + '0');
      sum -= toPush;
    }
    return ans;
  }
};
