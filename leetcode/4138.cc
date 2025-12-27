#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    static long long minCost(const string s, const vector<int>& cost) {
        const ll n = s.size();
        assert(n == cost.size());
        const ll tot = accumulate(cost.begin(), cost.end(), 0ll);
        unordered_map<char, ll> each;
        for (ll i = 0; i < n; ++i) {
            each[s[i]] += cost[i];
        }
        ll ans = LONG_LONG_MAX;
        for (const auto& p : each) {
            ans = min(ans, tot - p.second);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)