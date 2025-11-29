#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
  int ans = 0;

  int dfs(TreeNode *node) {
    int l = node->left ? dfs(node->left) : 0;
    int r = node->right ? dfs(node->right) : 0;
    int resl = node->left && node->left->val == node->val ? l + 1 : 0;
    int resr = node->right && node->right->val == node->val ? r + 1 : 0;
    ans = max(ans, resl + resr);
    return max(resl, resr);
  }

  int longestUnivaluePath(TreeNode *root) {
    if (!root) {
      return 0;
    }
    dfs(root);
    return ans;
  }
};
// @lc code=end
