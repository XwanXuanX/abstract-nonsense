#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static long long maxAlternatingSum(vector<int>& nums) {
        const ll n = nums.size(), plus_size = n % 2 ? n/2 + 1 : n/2;
        transform(nums.begin(), nums.end(), nums.begin(), [](const ll nn) { return nn * nn; });
        sort(nums.begin(), nums.end(), greater<ll>());
        ll ans = 0;
        for (ll i = 0; i < plus_size; ++i) ans += nums[i];
        for (ll i = plus_size; i < n; ++i) ans -= nums[i];
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)