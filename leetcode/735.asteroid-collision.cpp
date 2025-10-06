#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stk;
    for (int i = 0; i < asteroids.size(); ++i) {
      if (stk.empty()) {
        stk.push(asteroids[i]);
        continue;
      }
      if (stk.top() > 0 && asteroids[i] > 0) {
        stk.push(asteroids[i]);
      } else if (stk.top() > 0 && asteroids[i] < 0) {
        while (stk.size() && stk.top() > 0 && abs(stk.top()) < abs(asteroids[i])) {
          stk.pop();
        }
        if (stk.empty()) {
          stk.push(asteroids[i]);
        } else if (stk.top() > 0) {
          if (abs(stk.top()) == abs(asteroids[i])) {
            stk.pop();
          } else {
            assert(abs(stk.top()) > abs(asteroids[i]));
          }
        } else {
          assert(stk.top() < 0);
          stk.push(asteroids[i]);
        }
      } else if (stk.top() < 0 && asteroids[i] > 0) {
        stk.push(asteroids[i]);
      } else {
        stk.push(asteroids[i]);
      }
    }
    vector<int> ans;
    while (stk.size()) ans.push_back(stk.top()), stk.pop();
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

