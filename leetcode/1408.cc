#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int div(const int n, const int d) {
        if (n % d == 0) return n / d;
        return n / d + 1;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        const int n = nums.size();
        auto ok = [&](const int d) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += div(nums[i], d);
            }
            return sum <= threshold;
        };

        int l = 1, r = 1e6;
        int ans = INT_MAX;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (ok(mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)