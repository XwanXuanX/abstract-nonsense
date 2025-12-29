#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;
    static long long minOperations(const vector<int>& nums1, const vector<int>& nums2) {
        const ll n = nums1.size(), last = nums2[n];
        ll between = 0, ans = 0, dist = 1e9;
        for (ll i = 0; i < n; ++i) {
            const ll mn = min(nums1[i], nums2[i]), mx = max(nums1[i], nums2[i]);
            between |= mn <= last && last <= mx;
        }
        for (ll i = 0; i < n; ++i) ans += abs(nums1[i] - nums2[i]);
        if (between) return ans + 1;
        for (ll i = 0; i < n; ++i) dist = min(dist, abs(nums1[i] - last));
        for (ll i = 0; i < n; ++i) dist = min(dist, abs(nums2[i] - last));
        return ans + dist + 1;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)