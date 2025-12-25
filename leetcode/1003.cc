#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    static double minAreaFreeRect(const vector<vector<int>>& points) {
        const int n = points.size();
        double ans = DBL_MAX;
        map<tuple<ll, ll, ll>, vector<pair<int,int>>> groups;
        auto dist2 = [&](int i, int j) -> ll {
            const ll dx = points[i][0] - points[j][0], dy = points[i][1] - points[j][1];
            return dx * dx + dy * dy;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ll mx = points[i][0] + points[j][0], my = points[i][1] + points[j][1], d  = dist2(i, j);
                groups[{mx, my, d}].push_back({i, j});
            }
        }
        for (const auto& [key, diags] : groups) {
            const int m = diags.size();
            if (m < 2) continue;
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    const auto [a, b] = diags[i];
                    const auto [c, d] = diags[j];
                    const ll x1 = points[c][0] - points[a][0], y1 = points[c][1] - points[a][1];
                    const ll x2 = points[d][0] - points[a][0], y2 = points[d][1] - points[a][1];
                    const ll area2 = llabs(x1 * y2 - x2 * y1);
                    if (area2 > 0) {
                        ans = min(ans, static_cast<double>(area2));
                    }
                }
            }
        }
        return ans == DBL_MAX ? 0.0 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)