#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int conv(const int n) {
        vector<int> bits;
        for (int i = 0; i < 15; ++i) bits.push_back(static_cast<bool>(n & 1 << i));
        while (bits.size() && bits.back() == 0) bits.pop_back();
        const int sz = bits.size(), upper = sz % 2 ? sz/2 + 1 : sz/2;
        int ans = INT_MAX;
        for (int p = 0; p <= (1 << upper) - 1; ++p) {
            for (int i = 0; i < upper; ++i) bits[sz - 1 - i] = static_cast<bool>(p & 1 << i);
            for (int i = 0; i < sz / 2; ++i) bits[i] = bits[sz - 1 - i];
            assert(equal(bits.begin(), bits.begin() + sz / 2, bits.rbegin()));
            int nn = 0;
            for (int i = 0; i < sz; ++i) if (bits[i]) nn |= 1 << i;
            ans = min(ans, abs(nn - n));
        }
        return ans;
    }

    static vector<int> minOperations(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = conv(nums[i]);
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)