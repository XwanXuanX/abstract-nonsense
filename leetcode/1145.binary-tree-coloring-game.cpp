#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
 */
/**
 * the question is simple. firstly, it's always good to select a node
 * next to node x. there are 3 nodes to check. for each neighbor node,
 * check if y can secure more blue nodes than red nodes.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  map<int,vector<int>> G;

  void dfs(TreeNode* node, TreeNode* parent) {
    if (node == nullptr)
      return;
    if (node->left != nullptr)
      dfs(node->left, node);
    if (node->right != nullptr)
      dfs(node->right, node);
    if (node->left != nullptr)
      G[node->val].push_back(node->left->val);
    if (node->right != nullptr)
      G[node->val].push_back(node->right->val);
    if (parent != nullptr)
      G[node->val].push_back(parent->val);
  }

  int dfs2(int node, int parent) {
    if (G[node].size() == 1 && G[node][0] == parent)
      return 1;
    int tot = 0;
    for (auto adj : G[node])
      if (adj != parent)
        tot += dfs2(adj, node);
    return tot + 1;
  }

  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    dfs(root, nullptr);
    for (int i = 0; i < G[x].size(); ++i) {
      int select = G[x][i];
      int blue = dfs2(select, x);
      int red = n - blue;
      if (blue >= red) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

