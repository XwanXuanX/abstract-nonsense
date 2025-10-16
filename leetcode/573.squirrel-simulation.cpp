#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=573 lang=cpp
 *
 * [573] Squirrel Simulation
 */

// @lc code=start
class Solution {
public:
  int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
    int n = nuts.size();
    int t0 = tree[0], t1 = tree[1];
    int s0 = squirrel[0], s1 = squirrel[1];
    vector<int> distTree(n, 0), distSq(n, 0);
    for (int i = 0; i < n; ++i) {
      int n0 = nuts[i][0], n1 = nuts[i][1];
      distTree[i] = abs(t0 - n0) + abs(t1 - n1);
      distSq[i] = abs(s0 - n0) + abs(s1 - n1);
    }
    int totDist = accumulate(distTree.begin(), distTree.end(), 0);
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, distSq[i] + distTree[i] + (totDist - distTree[i])*2);
    }
    return ans;
  }
};
// @lc code=end

