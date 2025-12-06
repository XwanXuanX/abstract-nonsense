#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    long long maxNumber(long long n) {
        vector<ll> bits;
        for (ll i = 0; i < 64; ++i) {
            bits.push_back(n & (1ll << i));
        }
        ll msb = 0;
        for (ll i = 0; i < bits.size(); ++i) {
            if (bits[i])
                msb = max(msb, i);
        }
        ll ans = 0ll;
        for (ll i = 0; i < msb; ++i) {
            ans |= (1ll << i);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)