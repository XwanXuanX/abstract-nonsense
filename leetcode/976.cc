#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int minAreaRect(const vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> line;
        for (const auto& p : points) {
            const auto y = p[1], x = p[0];
            line[y].insert(x);
        }
        vector<pair<int, unordered_set<int>>> lines;
        for (auto&& l : line) {
            lines.push_back(std::move(l));
        }
        int ans = 1e9;
        const int n = lines.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const auto lo = min(lines[i].first, lines[j].first);
                const auto hi = max(lines[i].first, lines[j].first);
                vector<int> inter;
                for (const auto& p : lines[i].second) {
                    if (lines[j].second.count(p)) {
                        inter.push_back(p);
                    }
                }
                sort(inter.begin(), inter.end());
                const int m = inter.size();
                for (int k = 1; k < m; ++k) {
                    const int hor = inter[k] - inter[k - 1];
                    ans = min(ans, (hi - lo) * hor);
                }
            }
        }
        return ans == 1e9 ? 0 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)