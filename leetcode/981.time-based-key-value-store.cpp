#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
  unordered_map<string, vector<pair<int,string>>> mp;

  TimeMap() {
    mp.clear();
  }
  
  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }
  
  string get(string key, int timestamp) {
    auto& logs = mp[key];
    int before = -1;
    int l = 0, r = logs.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (logs[mid].first <= timestamp) {
        before = max(before, mid);
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (before == -1) {
      return {};
    }
    return logs[before].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

