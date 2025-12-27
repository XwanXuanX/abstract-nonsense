#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int maximumSum(const vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> ms(3, vector<int>());
        vector<int> mod0, mod1, mod2;
        for (int i = 0; i < n; ++i) {
            const int m = nums[i] % 3;
            ms[m].push_back(nums[i]);
        }
        for (int i = 0; i < 3; ++i) {
            sort(ms[i].begin(), ms[i].end(), greater<int>());
        }
        // Just try all combinations
        // 1. 1 + 1 + 1
        // 2. 1 + 2 + 0
        // 3. 0 + 0 + 0
        // 4. 2 + 2 + 2
        int ans = 0;
        if (ms[0].size() >= 3) ans = max(ans, ms[0][0] + ms[0][1] + ms[0][2]);
        if (ms[1].size() >= 3) ans = max(ans, ms[1][0] + ms[1][1] + ms[1][2]);
        if (ms[2].size() >= 3) ans = max(ans, ms[2][0] + ms[2][1] + ms[2][2]);
        if (ms[0].size() > 0 && ms[1].size() > 0 && ms[2].size() > 0)
            ans = max(ans, ms[0][0] + ms[1][0] + ms[2][0]);
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)