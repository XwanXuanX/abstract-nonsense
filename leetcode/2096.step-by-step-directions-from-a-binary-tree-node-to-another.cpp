#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
  bool dfs(TreeNode* node, int target, string& dir) {
    if (node == nullptr) {
      return false;
    }
    if (node->val == target) {
      return true;
    }
    if (node->left != nullptr) {
      dir.push_back('L');
      if (dfs(node->left, target, dir)) {
        return true;
      }
      dir.pop_back();
    }
    if (node->right != nullptr) {
      dir.push_back('R');
      if (dfs(node->right, target, dir)) {
        return true;
      }
      dir.pop_back();
    }
    return false;
  }

  string getDirections(TreeNode* root, int startValue, int destValue) {
    string leftDir, rightDir;
    assert(dfs(root, startValue, leftDir));
    assert(dfs(root, destValue, rightDir));
    // Find LCA
    int lca = -1;
    for (int i = 0; i < min(leftDir.size(), rightDir.size()); ++i) {
      if (leftDir[i] != rightDir[i]) {
        break;
      }
      lca = max(lca, i);
    }
    string ans;
    for (int i = 0; i < (int)leftDir.size() - lca - 1; ++i) {
      ans.push_back('U');
    }
    for (int i = lca + 1; i < (int)rightDir.size(); ++i) {
      ans.push_back(rightDir[i]);
    }
    return ans;
  }
};
// @lc code=end

