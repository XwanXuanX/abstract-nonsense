#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
  struct Job {
    int s;
    int e;
    int p;
  };

  int prev(vector<Job>& jobs, int istart, int end) {
    int l = 0, r = end;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (jobs[mid].e <= istart) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }

  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
      jobs[i].s = startTime[i];
      jobs[i].e = endTime[i];
      jobs[i].p = profit[i];
    }
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b){
      if (a.e != b.e) return a.e < b.e;
      return a.s < b.s;
    });
    vector<int> dp(n, 0);
    dp[0] = jobs[0].p;
    for (int i = 1; i < n; ++i) {
      dp[i] = max(dp[i], jobs[i].p);
      // Get the prev(i) = j such that endTime[j] <= startTime[i]
      int j = prev(jobs, jobs[i].s, i - 1);
      dp[i] = max(dp[i], dp[i-1]);
      if (j > -1) {
        dp[i] = max(dp[j] + jobs[i].p, dp[i-1]);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end

