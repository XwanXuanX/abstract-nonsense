#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=742 lang=cpp
 *
 * [742] Closest Leaf in a Binary Tree
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
  // We need to find the closest leaf for every node
  unordered_map<int, pair<int,int>> leaf;
  vector<int> path;

  pair<int,int> dfs(TreeNode* node) {
    assert(node != nullptr);
    if (node->left == nullptr && node->right == nullptr) {
      return leaf[node->val] = {node->val, 0};
    }
    pair<int,int> l, r, sub;
    if (node->left != nullptr) {
      l = dfs(node->left);
    }
    if (node->right != nullptr) {
      r = dfs(node->right);
    }
    if (l.first == 0) return leaf[node->val] = {r.first, r.second + 1};
    if (r.first == 0) return leaf[node->val] = {l.first, l.second + 1};
    assert(l.first != 0 && r.first != 0);
    if (l.second > r.second) {
      sub.first = r.first, sub.second = r.second + 1;
    } else {
      sub.first = l.first, sub.second = l.second + 1;
    }
    return leaf[node->val] = sub;
  }

  bool findPath(TreeNode* node, int k) {
    if (node == nullptr) {
      return false;
    }
    path.push_back(node->val);
    if (node->val == k) {
      return true;
    }
    if (node->left != nullptr && findPath(node->left, k)) {
      return true;
    }
    if (node->right != nullptr && findPath(node->right, k)) {
      return true;
    }
    path.pop_back();
    return false;
  }

  int findClosestLeaf(TreeNode* root, int k) {
    assert(root != nullptr);
    dfs(root);
    findPath(root, k);
    int ans = 0, dist = INT_MAX;
    for (int i = 0; i < (int)path.size(); ++i) {
      int node = path[i];
      int ndist = (int)path.size() - i  - 1 + leaf[node].second;
      if (ndist < dist) {
        dist = ndist;
        ans = leaf[node].first;
      }
    }
    return ans;
  }
};
// @lc code=end

