#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 */

// @lc code=start
class FindSumPairs {
public:
  unordered_map<int,int> cnt;
  vector<int> n1, n2;

  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    n1.assign(nums1.begin(), nums1.end());
    n2.assign(nums2.begin(), nums2.end());
    for (int x : nums2) {
      cnt[x]++;
    }
  }
  
  void add(int index, int val) {
    int old = n2[index];
    n2[index] += val;
    cnt[old]--;
    cnt[n2[index]]++;
  }
  
  int count(int tot) {
    int ans = 0;
    for (int x : n1) {
      int need = tot - x;
      if (cnt.count(need)) {
        ans += cnt[need];
      }
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end

