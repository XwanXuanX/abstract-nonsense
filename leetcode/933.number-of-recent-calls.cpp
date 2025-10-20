#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start
class RecentCounter {
public:
  deque<int> q;

  RecentCounter() {
    q.clear();
  }
  
  int ping(int t) {
    q.push_back(t);
    while (q.front() < t - 3000) {
      q.pop_front();
    }
    return q.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

