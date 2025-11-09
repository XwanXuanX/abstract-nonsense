#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
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
  TreeNode *dfs(TreeNode *node, int sum, int limit) {
    if (!node->left && !node->right) {
      return (sum + node->val < limit) ? nullptr : node;
    }
    if (node->left) {
      node->left = dfs(node->left, sum + node->val, limit);
    }
    if (node->right) {
      node->right = dfs(node->right, sum + node->val, limit);
    }
    return (!node->left && !node->right) ? nullptr : node;
  }

  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    return dfs(root, 0, limit);
  }
};
// @lc code=end
