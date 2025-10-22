#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2468 lang=cpp
 *
 * [2468] Split Message Based on Limit
 */

// @lc code=start
class Solution {
public:
/**
 * Binary search the number of chunks we need
 * There is a threshold x where # chunks >= x will work. Find it
 * For each chunk, we need to check if we can use this many chunk to represent
 * the entire message
 */

  vector<long long> digs;

  long long count(long long x) {
    long long res = 0;
    while (x) {
      res++, x /= 10;
    }
    return res;
  }

  bool ok(string& message, long long limit, long long chunk) {
    long long digSize = chunk * 3 + chunk * count(chunk) + digs[chunk];
    return chunk * limit >= message.size() + digSize;
  }

  vector<string> splitMessage(string message, long long limit) {
    digs.resize(1e4 + 100);
    digs[1] = 1;
    for (long long i = 2; i < digs.size(); ++i) {
      digs[i] += digs[i-1] + count(i);
    }
    long long lb = -1;
    for (int i = 1; i < 1e4 + 100; ++i) {
      if (ok(message, limit, i)) {
        lb = i;
        break;
      }
    }
    if (lb == -1) {
      return {};
    }
    vector<string> ans;
    long long cursor = 0, block = 1;
    for (long long i = 0; i < lb; ++i) {
      string blk;
      // Calclate # of chars to fit in
      long long fit = limit - count(block) - count(lb) - 3;
      assert(fit > 0);
      while (cursor < message.size() && fit) {
        blk.push_back(message[cursor]);
        cursor++;
        fit--;
      }
      // Then amend the footer
      blk += "<" + to_string(block) + "/" + to_string(lb) + ">";
      ans.push_back(blk);
      block++;
    }
    return ans;
  }
};
// @lc code=end

