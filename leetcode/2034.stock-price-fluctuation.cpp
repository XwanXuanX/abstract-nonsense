#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2034 lang=cpp
 *
 * [2034] Stock Price Fluctuation
 */

// @lc code=start
class StockPrice {
public:
  int latest = 0;
  unordered_map<int, int> umap;
  map<int, int> cnt;

  StockPrice() {}

  void update(int timestamp, int price) {
    if (timestamp > latest) {
      // This is a new record
      latest = max(latest, timestamp);
      umap[latest] = price;
      cnt[price]++;
    } else {
      if (umap.count(timestamp)) {
        // This is a correction
        int old = umap[timestamp];
        umap[timestamp] = price;
        assert(cnt.contains(old));
        cnt[old]--;
        if (cnt[old] == 0) {
          cnt.erase(old);
        }
        cnt[price]++;
      } else {
        umap[timestamp] = price;
        cnt[price]++;
      }
    }
  }

  int current() { return umap[latest]; }

  int maximum() {
    assert(cnt.size());
    return cnt.rbegin()->first;
  }

  int minimum() {
    assert(cnt.size());
    return cnt.begin()->first;
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
// @lc code=end
