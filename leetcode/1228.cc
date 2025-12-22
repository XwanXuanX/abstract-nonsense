#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;

    ll dfs(const vector<int>& arr, const ll l, const ll r) {
        if (l >= r) {
            return dp[l][r] = 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        }
        ll ans = 1e9;
        for (ll mid = l; mid < r; ++mid) {
            ll mxl = 0, mxr = 0;
            for (ll i = l; i <= mid; ++i) {
                mxl = max(mxl, static_cast<ll>(arr[i]));
            }
            for (ll i = mid + 1; i <= r; ++i) {
                mxr = max(mxr, static_cast<ll>(arr[i]));
            }
            const ll ll = dfs(arr, l, mid), rr = dfs(arr, mid + 1, r);
            ans = min(ans, ll + rr + (mxl * mxr));
        }
        return dp[l][r] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        const ll n = arr.size();
        dp.assign(n, vector<ll>(n, -1ll));
        return dfs(arr,0, n - 1);
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)