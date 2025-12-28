#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int minimumDistance(const vector<int>& nums) {
        const int n = nums.size();
        unordered_map<int, vector<int>> okr;
        for (int i = 0; i < n; ++i) okr[nums[i]].push_back(i);
        int ans = 1e9;
        for (const auto& p : okr)
            for (int i = 2; i < p.second.size(); ++i) ans = min(ans, p.second[i] - p.second[i - 2] + p.second[i] - p.second[i - 1] + p.second[i - 1] - p.second[i - 2]);
        return ans == 1e9 ? -1 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)