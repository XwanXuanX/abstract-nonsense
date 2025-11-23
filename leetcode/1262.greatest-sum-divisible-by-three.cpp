#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    int sum = 0;
    V<int> rem1, rem2;
    for (auto n : nums) {
      if (n % 3 == 0) {
        sum += n;
      } else if (n % 3 == 1) {
        rem1.push_back(n);
      } else {
        rem2.push_back(n);
      }
    }
    int tot = 0;
    ranges::sort(rem1, greater<int>());
    ranges::sort(rem2, greater<int>());
    int s1 = rem1.size(), s2 = rem2.size();
    for (int cntb = s1 - 2; cntb <= s1; ++cntb) {
      if (cntb >= 0) {
        for (int cntc = s2 - 2; cntc <= s2; ++cntc) {
          if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
            tot =
                max(tot, accumulate(rem1.begin(), rem1.begin() + cntb, 0) +
                             accumulate(rem2.begin(), rem2.begin() + cntc, 0));
          }
        }
      }
    }
    return sum + tot;
  }
};
// @lc code=end
