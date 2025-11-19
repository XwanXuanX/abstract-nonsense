#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
  int ans = INT_MIN;

  int dfs(TreeNode *node) {
    if (!node) {
      return 0;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    ans =
        max({ans, node->val + l + r, node->val, node->val + l, node->val + r});
    return max({l + node->val, r + node->val, node->val});
  }

  int maxPathSum(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
// @lc code=end
