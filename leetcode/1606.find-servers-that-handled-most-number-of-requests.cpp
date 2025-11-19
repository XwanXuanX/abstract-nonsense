#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1606 lang=cpp
 *
 * [1606] Find Servers That Handled Most Number of Requests
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
    V<int> cnt(k, 0);
    set<int> free;
    priority_queue<pair<int, int>, V<pair<int, int>>, greater<>> busy;

    for (int i = 0; i < k; ++i) {
      free.insert(i);
    }
    for (int i = 0; i < (int)arrival.size(); ++i) {
      int start = arrival[i];
      // Move busy servers to free list
      while (busy.size() && busy.top().first <= start) {
        auto [_, id] = busy.top();
        busy.pop();
        free.insert(id);
      }
      // Assign server for ith task
      // If there are no servers, then the task is dropped
      if (free.empty()) {
        continue;
      }
      // Otherwise, assign to the smallest server id that's creater than i
      auto it = free.lower_bound(i % k);
      if (it == free.end()) {
        it = free.begin();
      }
      busy.push({start + load[i], *it});
      cnt[*it]++;
      free.erase(it);
    }

    int mx = 0;
    V<int> ans;
    for (int i = 0; i < k; ++i) {
      mx = max(mx, cnt[i]);
    }
    for (int i = 0; i < k; ++i) {
      if (cnt[i] == mx) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
// @lc code=end
