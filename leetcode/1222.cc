#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                const auto& int1 = intervals[i], &int2 = intervals[j];
                if (int2[0] <= int1[0] && int1[1] <= int2[1]) {
                    ans++;
                    break;
                }
            }
        }
        return n - ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)