#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto& e: arr) {
      pq.push({abs(e - x), e});
    }
    vector<int> ans;
    while (k--) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

