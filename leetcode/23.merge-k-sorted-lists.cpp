#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
struct comp {
  bool operator()(const ListNode *const n1, const ListNode *const n2) const {
    return n1->val < n2->val;
  }
};

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    multiset<ListNode *, comp> q;
    for (auto *p : lists) {
      if (p) {
        q.insert(p);
      }
    }
    ListNode *head = new ListNode();
    ListNode *phead = head;
    while (q.size()) {
      auto *small = *q.begin();
      q.erase(q.begin());
      ListNode *nn = new ListNode(small->val);
      phead->next = nn;
      phead = phead->next;
      if (small->next != nullptr) {
        small = small->next;
        q.insert(small);
      }
    }
    return head->next;
  }
};
// @lc code=end
