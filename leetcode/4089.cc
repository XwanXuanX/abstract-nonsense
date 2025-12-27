#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static long long maxPoints(const vector<int>& technique1, const vector<int>& technique2, const int k) {
        const ll n = technique1.size();
        vector<ll> ind(n), completed(n, false);
        for (ll i = 0; i < n; ++i) ind[i] = i;
        sort(ind.begin(), ind.end(), [&](const ll i1, const ll i2) {
            const ll d1 = technique1[i1] - technique2[i1], d2 = technique1[i2] - technique2[i2];
            return d1 > d2;
        });
        ll ans = 0;
        for (ll i = 0; i < k; ++i) ans += technique1[ind[i]], completed[ind[i]] = true;
        for (ll i = 0; i < n; ++i) if (!completed[i]) ans += max(technique1[i], technique2[i]);
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)