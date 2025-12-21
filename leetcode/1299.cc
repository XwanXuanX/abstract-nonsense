#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const ll n = arr.size();
        ll mxSub = 0, pfs = 0, mn = 0, mx1 = 0, mx2 = 0;
        for (ll i = 0; i < n; ++i) {
            pfs += arr[i];
            mxSub = max(mxSub, pfs - mn);
            mn = min(mn, pfs), mx1 = max(mx1, pfs);
        }
        if (k == 1) {
            return mxSub;
        }
        const ll tot = accumulate(arr.begin(), arr.end(), 0ll);
        pfs = 0;
        for (ll i = n - 1; i >= 0; --i) {
            pfs += arr[i];
            mx2 = max(mx2, pfs);
        }
        const ll mxPs = mx1 + mx2;
        return max(mxSub, mxPs + (tot > 0 ? tot * (k - 2) : 0)) % mod;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)