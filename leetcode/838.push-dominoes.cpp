#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */
/**
 * Basically we are interested in finding any R...L segments
 * other segments like R...R or L...L or L...R does not 
 * need to be considered
 */

// @lc code=start
class Solution {
public:
  string pushDominoes(string dominoes) {
    int n = dominoes.size();
    vector<int> a(n, 0), b(n, 0), c(n, 0);

    // Step 1: Push any L to the left until meet a R
    int ongoing = false;
    for (int i = n - 1; i >= 0; --i) {
      if (dominoes[i] == 'L') ongoing = true;
      else if (dominoes[i] == 'R') ongoing = false;
      if (ongoing) a[i]++, c[i]++;
    }

    // Step 2: Push any R to the right until meet a L
    ongoing = false;
    for (int i = 0; i < n; ++i) {
      if (dominoes[i] == 'R') ongoing = true;
      else if (dominoes[i] == 'L') ongoing = false;
      if (ongoing) b[i]++, c[i]++;
    }

    // Step 3: Find any subarray of 2s. fix those
    vector<pair<int,int>> seg;
    int start = 0;
    for (int i = 1; i < n; ++i) {
      if (c[i] != c[i-1]) {
        if (c[i-1] == 2) seg.push_back(make_pair(start, i-1));
        start = i;
      }
    }
    if (seg.size() > 0 && seg.front().first == 0)
      seg.erase(seg.begin());
    string ans(n, '.');
    for (int i = 0; i < n; ++i) {
      if (c[i] == 1 && a[i] == 1) ans[i] = 'L';
      else if (c[i] == 1 && b[i] == 1) ans[i] = 'R';
      else if (c[i] == 0) ans[i] = '.';
    }
    for (auto& [l, r] : seg) {
      int len = r - l + 1;
      int mid = l + (len / 2);
      std::fill(ans.begin() + l, ans.begin() + mid, 'R');
      if (len & 1) a[mid] = '.';
      std::fill(ans.begin() + mid + (len & 1), ans.begin() + r + 1, 'L');
    }
    return ans;
  }
};
// @lc code=end

