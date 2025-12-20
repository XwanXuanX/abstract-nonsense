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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<int> lvl;
        Q.push(root);
        while (Q.size()) {
            int tot = 0;
            const int sz = Q.size();
            for (int i = 0; i < sz; ++i) {
                const auto node = Q.front();
                Q.pop();
                tot += node->val;
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            lvl.push_back(tot);
        }
        return max_element(lvl.begin(), lvl.end()) - lvl.begin() + 1;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)