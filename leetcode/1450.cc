#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static TreeNode* dfs(TreeNode* node, const int target) {
        if (!node->left && !node->right) {
            return node->val == target ? nullptr : node;
        }
        TreeNode* l = nullptr, *r = nullptr;
        if (node->left) {
            l = dfs(node->left, target);
        }
        if (node->right) {
            r = dfs(node->right, target);
        }
        node->left = l, node->right = r;
        if (!node->left && !node->right) {
            return node->val == target ? nullptr : node;
        }
        return node;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target);
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)