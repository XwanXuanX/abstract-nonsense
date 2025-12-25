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
    vector<int> ans;

    int dfs(const TreeNode* node, const vector<int>& voy, const int ind) {
        if (!node) return 0;
        if (node->val != voy[ind]) return -1;
        if (!node->left && !node->right) return 1;
        const int next = voy[ind + 1];
        const int lv = node->left ? node->left->val : -1;
        const int rv = node->right ? node->right->val : -1;
        if (next != lv && next != rv) {
            return -1;
        }
        int l_sub, r_sub;
        if (next == lv) {
            l_sub = dfs(node->left, voy, ind + 1);
            r_sub = dfs(node->right, voy, ind + 1 + l_sub);
        } else {
            if (node->left) ans.push_back(node->val);
            r_sub = dfs(node->right, voy, ind + 1);
            l_sub = dfs(node->left, voy, ind + 1 + r_sub);
        }
        if (l_sub == -1 || r_sub == -1) return -1;
        return l_sub + 1 + r_sub;
    }

    vector<int> flipMatchVoyage(const TreeNode* root, const vector<int>& voyage) {
        if (dfs(root, voyage, 0) == -1) {
            return {-1};
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)