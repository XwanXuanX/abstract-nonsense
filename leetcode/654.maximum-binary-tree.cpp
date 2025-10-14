#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
  // We use post order dfs
  TreeNode* construct(vector<int>& nums, int l, int r) {
    if (l > r) {
      return nullptr;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }
    int mx = -1, mxi = -1;
    for (int i = l; i <= r; ++i) {
      if (nums[i] > mx) {
        mx = max(mx, nums[i]);
        mxi = i;
      }
    }
    TreeNode* left = construct(nums, l, mxi - 1);
    TreeNode* right = construct(nums, mxi + 1, r);
    TreeNode* sub = new TreeNode(mx);
    sub->left = left, sub->right = right;
    return sub;
  }

  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size() - 1);
  }
};
// @lc code=end

