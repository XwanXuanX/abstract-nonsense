#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
public:
  int snapId = 0;
  vector<int> arr;
  vector<vector<pair<int,int>>> snapArr;
  unordered_set<int> changed;

  SnapshotArray(int length) {
    arr.clear(), snapArr.clear(), changed.clear();
    arr.resize(length);
    snapArr.resize(length);
  }
  
  void set(int index, int val) {
    if (arr[index] != val) {
      arr[index] = val;
      changed.insert(index);
    }
  }
  
  int snap() {
    // You only need to snap the elements thats changed since last snap
    for (int idx : changed) {
      snapArr[idx].push_back({snapId, arr[idx]});
    }
    changed.clear();
    int oldId = snapId;
    snapId++;
    return oldId;
  }
  
  int get(int index, int snap_id) {
    // Since the snap ids are monotonic, we can do binary search
    vector<pair<int,int>>& v = snapArr[index];
    int before = -1;
    int l = 0, r = v.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (v[mid].first == snap_id) {
        // If we find the target snapshot, we are done
        return v[mid].second;
      } else if (v[mid].first > snap_id) {
        r = mid - 1;
      } else {
        before = max(before, mid);
        l = mid + 1;
      }
    }
    if (before == -1) {
      return 0;
    }
    // We didn't find the target snap id, so we use the snapshot before it
    return v[before].second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

