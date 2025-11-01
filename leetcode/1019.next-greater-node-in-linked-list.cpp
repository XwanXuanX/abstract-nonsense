#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> v;
    while (head != nullptr) {
      v.push_back(head->val);
      head = head->next;
    }
    int n = v.size();
    stack<int> stk;
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      while (!stk.empty() && v[i] >= stk.top()) {
        stk.pop();
      }
      if (!stk.empty()) {
        ans[i] = stk.top();
      }
      stk.push(v[i]);
    }
    return ans;
  }
};
// @lc code=end
