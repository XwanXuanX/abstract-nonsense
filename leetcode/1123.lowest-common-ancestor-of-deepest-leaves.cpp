#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
  unordered_map<int, int> height;
  TreeNode *ans = nullptr;

  void dfs(TreeNode *node, int h) {
    if (node == nullptr) {
      return;
    }
    height[node->val] = h;
    dfs(node->left, h + 1), dfs(node->right, h + 1);
  }

  int dfs2(TreeNode *node, int cnt, int mxHeight) {
    if (!node->left && !node->right) {
      if (height[node->val] == mxHeight && cnt == 1 && ans == nullptr) {
        ans = node;
      }
      return height[node->val] == mxHeight;
    }
    int l = 0, r = 0;
    if (node->left) {
      l = dfs2(node->left, cnt, mxHeight);
    }
    if (node->right) {
      r = dfs2(node->right, cnt, mxHeight);
    }
    if (l + r == cnt && ans == nullptr) {
      ans = node;
    }
    return l + r;
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    dfs(root, 0);
    int mxHeight = 0, cnt = 0;
    for (auto &p : height) {
      mxHeight = max(mxHeight, p.second);
    }
    for (auto &p : height) {
      if (p.second == mxHeight) {
        cnt++;
      }
    }
    dfs2(root, cnt, mxHeight);
    return ans;
  }
};
// @lc code=end
