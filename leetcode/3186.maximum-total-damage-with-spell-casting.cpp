#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
class Solution {
public:
  long long lowerBoundMinus1(vector<int>& power, long long end, long long target) {
    long long ans = -1;
    long long l = 0, r = end;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      if (power[mid] < target) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

  long long maximumTotalDamage(vector<int>& power) {
    long long n = power.size();
    sort(power.begin(), power.end());
    unordered_map<long long,long long> cnt;
    for (auto x : power) {
      cnt[x]++;
    }

    vector<long long> dp(n, 0);
    dp[0] = power[0] * cnt[power[0]];
    for (long long i = 1; i < n; ++i) {
      // For any state, you can only pick self, or do nothing
      dp[i] = max({dp[i], power[i] * cnt[power[i]], dp[i-1]});
      long long lb = lowerBoundMinus1(power, i - 1, power[i] - 2);
      if (lb > -1) {
        // If you pick self, then better pick all of them
        dp[i] = max(dp[i], dp[lb] + (power[i] * cnt[power[i]]));
      }
    }
    return dp[n-1];
  }
};
// @lc code=end

