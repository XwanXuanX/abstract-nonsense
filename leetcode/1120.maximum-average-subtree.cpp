#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1120 lang=cpp
 *
 * [1120] Maximum Average Subtree
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
  double ans = 0;

  pair<int, int> dfs(TreeNode *node) {
    if (!node->left && !node->right) {
      ans = max(ans, (double)node->val);
      return {node->val, 1};
    }
    pair<int, int> l, r;
    if (node->left) {
      l = dfs(node->left);
    }
    if (node->right) {
      r = dfs(node->right);
    }
    double tot_val = l.first + r.first + node->val;
    double tot_num = l.second + r.second + 1;
    ans = max(ans, tot_val / tot_num);
    return {tot_val, tot_num};
  }

  double maximumAverageSubtree(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
// @lc code=end
