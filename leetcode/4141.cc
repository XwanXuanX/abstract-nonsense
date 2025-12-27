#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int countElements(vector<int>& nums, const int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        auto qualified = [&](const int t) -> int {
            const int ind = upper_bound(nums.begin(), nums.end(), t) - nums.begin();
            const int remain = n - ind;
            return remain >= k;
        };
        int l = 0, r = n - 1, ans = 0;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (qualified(nums[mid])) ans = max(ans, mid + 1), l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)