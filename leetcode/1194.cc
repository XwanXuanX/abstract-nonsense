#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    vector<int> pathInZigZagTree(int label) {
        vector<pair<ll, ll>> lvl;
        lvl.push_back({1, 1});
        for (ll i = 1; i < 31; ++i) {
            auto [_, end] = lvl[i - 1];
            lvl.push_back({end + 1, (1ll << (i + 1)) - 1});
        }
        ll lv = 0;
        for (ll i = 0; i < lvl.size(); ++i) {
            if (lvl[i].first <= label && label <= lvl[i].second) {
                lv = i;
            }
        }
        vector<int> ans;
        while (lv) {
            auto [cs, ce] = lvl[lv];
            auto [ps, pe] = lvl[lv - 1];
            const ll ith = (label - cs) / 2;
            ans.push_back(label);
            label = pe - ith;
            lv--;
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)