#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int countMajoritySubarrays(const vector<int>& nums, const int target) {
        const int n = nums.size();
        int ans = 0;
        vector<int> asd(n, 0);
        for (int i = 0; i < n; ++i) asd[i] = nums[i] == target;
        for (int i = 1; i < n; ++i) asd[i] += asd[i - 1];
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) {
                const int l = j - i + 1, cnt = asd[j] - (i > 0 ? asd[i - 1] : 0);
                ans += static_cast<int>(cnt >= l/2 + 1);
            }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)