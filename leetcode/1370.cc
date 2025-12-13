#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> odd = {-1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2) {
                odd.push_back(i);
            }
        }
        odd.push_back(n);
        int ans = 0;
        for (int l = 1, r = k; r < odd.size() - 1; ++l, ++r) {
            const int lb = odd[l - 1] + 1, rb = odd[r + 1] - 1;
            const int lm = odd[l] - lb + 1, rm = rb - odd[r] + 1;
            ans += lm * rm;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)