#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int OR = 0;
            for (int j = i; j >= 0; --j) {
                OR |= nums[j];
                if (OR >= k) {
                    ans = min(ans, i - j + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)