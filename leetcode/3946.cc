#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int maxBalancedSubarray(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> pfs(n, 0), eo(n, 0), pfs2(n, 0);
        pfs[0] = nums[0], eo[0] = nums[0] % 2 ? -1 : +1, pfs2[0] = eo[0];
        for (int i = 1; i < n; ++i) pfs[i] = pfs[i - 1] ^ nums[i];
        for (int i = 1; i < n; ++i) eo[i] = nums[i] % 2 ? -1 : +1;
        for (int i = 1; i < n; ++i) pfs2[i] = pfs2[i - 1] + eo[i];
        map<pair<int, int>, int> okr; okr[{0, 0}] = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            const pair<int, int> lookup = {pfs[i], pfs2[i]};
            if (okr.count(lookup)) ans = max(ans, i - okr[lookup]);
            else okr[lookup] = i;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)