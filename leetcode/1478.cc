#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int n = events.size();
        int mxe = 0, ans = 0;
        unordered_map<int, vector<int>> es;
        for (auto& e : events) {
            es[e[0]].push_back(e[1]);
            mxe = max(mxe, e[1]);
        }
        map<int, int> ends;
        for (int d = 1; d <= mxe; ++d) {
            for (auto& end : es[d]) {
                ends[end]++;
            }
            while (!ends.empty() && ends.begin()->first < d) {
                ends.erase(ends.begin());
            }
            if (!ends.empty()) {
                ans++;
                const auto it = ends.begin();
                it->second--;
                if (it->second == 0) {
                    ends.erase(it);
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)