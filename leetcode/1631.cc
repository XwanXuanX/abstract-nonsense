#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static constexpr ll mod = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        ll n = arr.size();
        ll ans = 0, co = 0, ce = 1, pfs = 0;
        for (ll i = 0; i < n; ++i) {
            pfs += arr[i];
            if (pfs % 2) {
                ans = ((ans % mod) + (ce % mod)) % mod;
                co++;
            } else {
                ans = ((ans % mod) + (co % mod)) % mod;
                ce++;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)