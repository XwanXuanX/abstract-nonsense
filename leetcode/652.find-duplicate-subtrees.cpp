#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
  unordered_map<string, vector<TreeNode*>> mp;

  // We use the post order dfs
  string dfs(TreeNode* node) {
    if (node == nullptr) {
      return {};
    }
    string left = "L" + dfs(node->left);
    string right = "R" + dfs(node->right);
    string sub = left + to_string(node->val) + right;
    mp[sub].push_back(node);
    return sub;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    vector<TreeNode*> ans;
    for (auto& p : mp) {
      if (p.second.size() > 1) {
        ans.push_back(p.second.front());
      }
    }
    return ans;
  }
};
// @lc code=end
