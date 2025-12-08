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
    using ll = long long;
    unordered_map<const TreeNode*, ll> sub;
    static constexpr ll mod = 1e9 + 7;

    ll dfs(const TreeNode* const node) {
        if (node == nullptr)
            return 0;
        const ll l = dfs(node->left), r = dfs(node->right);
        const ll tot = l + node->val + r;
        sub[node] = tot;
        return tot;
    }

    int maxProduct(TreeNode* root) {
        dfs(root);
        ll ans = 0;
        assert(sub.count(root));
        const auto tot = sub[root];
        for (auto& p : sub) {
            if (p.first == root) {
                continue;
            }
            const auto rest = tot - p.second;
            ans = max(ans, rest * p.second);
        }
        return ans % mod;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)