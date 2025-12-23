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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1 || !root2 || root1->val != root2->val) {
            return false;
        }
        const bool no_change = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        const bool swapped = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
        return no_change || swapped;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)