#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        ll n = conversions.size() + 1;
        unordered_map<ll, vector<pair<ll, ll>>> G;
        for (auto& e : conversions) {
            ll s = e[0], d = e[1], f = e[2];
            G[s].push_back({d, f});
        }
        vector<int> ans(n, -1);
        deque<pair<ll, ll>> Q;
        Q.push_back({0, 1});
        while (!Q.empty()) {
            auto [nod, fac] = Q.front();
            Q.pop_front();
            ans[nod] = fac;
            for (auto& p : G[nod]) {
                assert(ans[p.first] == -1);
                Q.push_back({p.first, ((fac % mod) * (p.second % mod)) % mod});
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)