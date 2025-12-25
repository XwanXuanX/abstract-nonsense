#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int maxWidthRamp(const vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        unordered_map<int, int> ind;
        set<int> seen;
        for (int i = 0; i < n; ++i) {
            const int cur = nums[i];
            auto it = seen.upper_bound(cur);
            if (it == seen.begin()) {
                ind[cur] = i;
            } else {
                --it;
                assert(ind.count(*it));
                ans = max(ans, i - ind[*it]);
                if (!ind.count(cur)) {
                    ind[cur] = ind[*it];
                }
            }
            seen.insert(cur);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)