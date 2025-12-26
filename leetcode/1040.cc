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
    static TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        assert(root->val != val);
        if (root->val < val) {
            const auto new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)