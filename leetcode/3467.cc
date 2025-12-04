#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    ll val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(ll x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    int minimumLevel(TreeNode *root) {
        ll ans = 0, mn = LLONG_MAX;
        ll level = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            const ll sz = Q.size();
            ll sum = 0;
            for (ll _ = 0; _ < sz; ++_) {
                const auto* nod = Q.front();
                Q.pop();
                sum += nod->val;
                if (nod->left) {
                    Q.push(nod->left);
                }
                if (nod->right) {
                    Q.push(nod->right);
                }
            }
            if (sum < mn) {
                mn = sum;
                ans = level;
            }
            level++;
        }
        return static_cast<int>(ans);
    }
};
// IMPORTANT!! Submit Code Region End(Do not remove this line)