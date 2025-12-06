#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        const ll n = nums.size();
        sort(nums.begin(), nums.end());
        const ll mi = n / 2;
        if (nums[mi] == k) {
            return 0;
        }
        ll ans = abs(nums[mi] - k);
        if (nums[mi] > k) {
            nums[mi] = k;
            for (ll i = mi - 1; i >= 0; --i) {
                if (nums[i] <= nums[i + 1])
                    break;
                ans += abs(nums[i] - nums[i + 1]), nums[i] = nums[i + 1];
            }
        } else {
            nums[mi] = k;
            for (ll i = mi + 1; i < n; ++i) {
                if (nums[i - 1] <= nums[i])
                    break;
                ans += abs(nums[i] - nums[i - 1]), nums[i] = nums[i - 1];
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)