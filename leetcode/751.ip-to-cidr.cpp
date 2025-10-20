#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=751 lang=cpp
 *
 * [751] IP to CIDR
 */

// @lc code=start
class Solution {
public:
  unsigned toInt(string ip) {
    unsigned result = 0;
    stringstream ss(ip);
    string section;
    while (getline(ss, section, '.')) {
      result <<= 8;
      result += stoi(section);
    }
    return result;
  }

  string toString(unsigned ip, unsigned trailing) {
    stringstream ss;
    ss << (ip >> 24) << ".";
    ss << ((ip << 8) >> 24) << ".";
    ss << ((ip << 16) >> 24) << ".";
    ss << ((ip << 24) >> 24);
    ss << "/" << trailing;
    return ss.str();
  }

  vector<string> ipToCIDR(string ip, unsigned n) {
    vector<string> result;
    unsigned start = toInt(ip);
    unsigned end = start + n - 1;
    while (start <= end) {
      unsigned trailing = 0;
      while (trailing < 31 && (start & (1 << trailing)) == 0) {
        trailing++;
      }
      while (end < start + (1 << trailing) - 1) {
        trailing--;
      }
      result.push_back(toString(start, 32 - trailing));
      start += 1 << trailing;
    }
    return result;
  }
};
// @lc code=end

