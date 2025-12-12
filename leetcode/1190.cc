#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    unordered_map<string, int> id;
    unordered_map<int, string> di;

    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_set<string> reg;
        for (const auto& r : regions) {
            for (const auto& rr : r) {
                reg.insert(rr);
            }
        }
        int last = 0;
        for (const auto& r : reg) {
            id[r] = last;
            di[last] = r;
            last++;
        }
        unordered_map<int, vector<int>> T;
        for (const auto& r : regions) {
            const int par = id[r[0]];
            for (int i = 1; i < r.size(); ++i) {
                T[par].push_back(id[r[i]]);
            }
        }
        int ans = -1;
        const int r1 = id[region1], r2 = id[region2];
        unordered_map<int, pair<int, int>> dp;
        function<pair<int, int>(const int)> dfs;
        dfs = [&](const int node) -> pair<int, int> {
            if (dp.count(node)) {
                return dp[node];
            }
            int f1 = node == r1, f2 = node == r2;
            if (!T.count(node)) {
                return dp[node] = {f1, f2};
            }
            for (const auto& adj : T[node]) {
                const auto& res = dfs(adj);
                f1 |= res.first, f2 |= res.second;
            }
            if (f1 && f2) {
                if (ans == -1) {
                    ans = node;
                }
                return dp[node] = {1, 1};
            }
            return dp[node] = {f1, f2};
        };
        for (int i = 0; i < reg.size(); ++i) {
            (void) dfs(i);
            if (ans != -1) {
                break;
            }
        }
        return di[ans];
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)