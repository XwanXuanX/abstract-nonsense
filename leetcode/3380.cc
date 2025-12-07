#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<int> cnt;

    void update(const int n, int d) {
        for (int p = 0; p < 32; p++)
            if ((n >> p) & 1)
                cnt[p] += d;
    }

    int convert() const {
        int res = 0;
        for (int p = 0; p < 32; p++)
            if (cnt[p] != 0)
                res |= 1 << p;
        return res;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        cnt.assign(32, 0);
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n; ++r) {
            update(nums[r], 1);
            while (l <= r && convert() >= k) {
                ans = min(ans, r - l + 1);
                update(nums[l], -1);
                l++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)