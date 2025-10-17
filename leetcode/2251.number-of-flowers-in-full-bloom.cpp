#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution {
public:
  vector<int> start, finish;

  int search(vector<int>& arr, int target) {
    int ans = -1;
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (arr[mid] <= target) {
        ans = max(ans, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (ans == -1) {
      return 0;
    }
    return ans + 1;
  }
  
  vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    for (int i = 0; i < flowers.size(); ++i) {
      start.push_back(flowers[i][0]);
      finish.push_back(flowers[i][1]);
    }
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());

    int n = people.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      int started = search(start, people[i]);
      int ended = search(finish, people[i] - 1);
      ans[i] = started - ended;
    }

    return ans;
  }
};
// @lc code=end

