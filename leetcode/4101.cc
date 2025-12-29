#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static long long maxProduct(const vector<int>& nums) {
        const ll n = nums.size();
        // Three cases:
        // 1. neg * neg * 1e5
        // 2. pos * pos * 1e5
        // 3. neg * pos * -1e5
        ll ans = 0;
        vector<ll> pos, neg;
        for (ll i = 0; i < n; ++i) if (nums[i] < 0) neg.push_back(nums[i]);
        for (ll i = 0; i < n; ++i) if (nums[i] > 0) pos.push_back(nums[i]);
        sort(pos.begin(), pos.end(), greater<ll>());
        sort(neg.begin(), neg.end(), less<ll>());
        if (neg.size() >= 2) ans = max(ans, neg[0] * neg[1] * static_cast<ll>(1e5));
        if (pos.size() >= 2) ans = max(ans, pos[0] * pos[1] * static_cast<ll>(1e5));
        if (neg.size() >= 1 && pos.size() >= 1) ans = max(ans, neg[0] * pos[0] * static_cast<ll>(-1e5));
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)