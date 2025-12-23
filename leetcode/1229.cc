#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    enum { r, b };
    struct cord { int node, color, step; };
    unordered_map<int, vector<pair<int, int>>> G;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for (const auto& e : redEdges) {
            G[e[0]].push_back({e[1], r});
        }
        for (const auto& e : blueEdges) {
            G[e[0]].push_back({e[1], b});
        }
        vector<int> ans(n, 1e9);
        vector<vector<int>> V(n, vector<int>(2, 0));
        queue<cord> Q;
        Q.push({0, -1, 0});
        V[0][r] = V[0][b] = 1;
        while (Q.size()) {
            const auto [node, color, step] = Q.front();
            Q.pop();
            ans[node] = min(ans[node], step);
            for (const auto& p : G[node]) {
                if (p.second == color || V[p.first][p.second]) {
                    continue;
                }
                Q.push({p.first, p.second, step + 1});
                V[p.first][p.second] = 1;
            }
        }
        for (auto& d : ans) {
            if (d == 1e9) {
                d = -1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)