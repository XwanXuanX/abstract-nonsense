#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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

  pair<int, int> dfs(TreeNode *node) {
    assert(node != nullptr);
    pair<int, int> ltree, rtree;
    ltree = rtree = {1e9, -1e9};
    if (node->left != nullptr) {
      ltree = dfs(node->left);
    }
    if (node->right != nullptr) {
      rtree = dfs(node->right);
    }
    int mn = min(ltree.first, rtree.first);
    int mx = max(ltree.second, rtree.second);
    if (mn != 1e9) {
      ans = max(ans, abs(node->val - mn));
    }
    if (mx != -1e9) {
      ans = max(ans, abs(node->val - mx));
    }
    return {min(mn, node->val), max(mx, node->val)};
  }

  int maxAncestorDiff(TreeNode *root) {
    dfs(root);
    return ans;
  }
};
// @lc code=end
