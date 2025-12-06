#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        vector<ll> l(n, 0), r(n, 0);
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                r[i] += grid[i][j];
            }
        }
        ll ans = 0;
        for (ll j = 0; j < m; ++j) {
            for (ll i = 0; i < n; ++i) {
                r[i] -= grid[i][j];
            }
            ll sum = 0, cnt = 0;
            for (ll i = 0; i < n; ++i) {
                if (grid[i][j])
                    sum += l[i] + r[i], cnt++;
            }
            ans += (cnt - 1) * sum;
            for (ll i = 0; i < n; ++i) {
                l[i] += grid[i][j];
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)