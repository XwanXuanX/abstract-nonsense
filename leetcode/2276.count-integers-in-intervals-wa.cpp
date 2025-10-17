#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2276 lang=cpp
 *
 * [2276] Count Integers in Intervals
 */

// @lc code=start
class CountIntervals {
public:
  set<int> starts;
  map<int,int> range;
  int tot = 0;

  CountIntervals() {}
  
  void add(int left, int right) {
    if (starts.empty()) {
      tot += right - left + 1;
      starts.insert(left);
      range[left] = right;
      return;
    }
    auto it = starts.upper_bound(left);
    if (it == starts.end()) { // Only check the previous one
      --it;
      int x = *it, y = range[x];
      if (y + 1 >= left) { // Then we need to merge
        tot = tot - (y - x + 1) + (max(y, right) - x + 1);
        range[x] = max(y, right);
      } else { // No overlap
        tot += right - left + 1;
        starts.insert(left);
        range[left] = right;
      }
      return;
    }
    if (it == starts.begin()) { // Only check the first one
      int x = *it, y = range[x];
      if (right + 1 >= x) { // Then we need to merge
        tot = tot - (y - x + 1) + (max(right, y) - left + 1);
        starts.erase(it);
        range.erase(x);
        starts.insert(left);
        range[left] = max(right, y);
      } else { // No overlap
        tot += right - left + 1;
        starts.insert(left);
        range[left] = right;
      }
      return;
    }
    // Normal case, check both it-- and it
    // Case it
    int x = *it, y = range[x];
    if (right + 1 >= x) { // Then we need to merge
      tot -= (y - x + 1);
      starts.erase(it);
      range.erase(x);
      right = max(right, y);
    } // No overlap do nothing
    --it;
    x = *it, y = range[x];
    if (y + 1 >= left) { // Then we need to merge
      tot = tot - (y - x + 1) + (max(y, right) - x + 1);
      range[x] = max(y, right);
    } else { // No overlap
      tot += right - left + 1;
      starts.insert(left);
      range[left] = right;
    }
  }
  
  int count() {
    return tot;
  }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end

