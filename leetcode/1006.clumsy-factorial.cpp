#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

// @lc code=start
class Solution {
public:
  int clumsy(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 6;
    int copy = n;
    vector<int> parts;
    while (n) {
      if (n < 4) {
        if (n == 1) {
          parts.push_back(n);
        } else if (n == 2) {
          parts.push_back(n * (n - 1));
        } else {
          parts.push_back(n * (n - 1) / (n - 2));
        }
        break;
      }
      parts.push_back((n * (n - 1) / (n - 2)) - (n - 3));
      n -= 4;
    }
    int ans = 2 * (copy * (copy - 1) / (copy - 2));
    for (int i = 0; i < parts.size(); ++i) {
      ans -= parts[i];
    }
    return ans;
  }
};
// @lc code=end
