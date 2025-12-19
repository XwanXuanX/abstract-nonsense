#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        const int n = s.size();
        unordered_map<int, vector<int>> G;
        for (const auto& e : pairs) {
            const int u = e[0], v = e[1];
            G[u].push_back(v), G[v].push_back(u);
        }
        vector<vector<int>> cc;
        unordered_set<int> V;
        function<void(const int, vector<int>&)> dfs;
        dfs = [&](const int node, vector<int>& ccc) {
            assert(!V.count(node));
            V.insert(node);
            ccc.push_back(node);
            for (const auto& adj : G[node]) {
                if (!V.count(adj)) {
                    dfs(adj, ccc);
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!V.count(i)) {
                vector<int> ccc;
                dfs(i, ccc);
                cc.push_back(std::move(ccc));
            }
        }
        for (auto& ccc : cc) {
            string sorted;
            for (const auto c : ccc) {
                sorted.push_back(s[c]);
            }
            int ind = 0;
            sort(sorted.begin(), sorted.end());
            sort(ccc.begin(), ccc.end());
            for (const auto c : ccc) {
                s[c] = sorted[ind++];
            }
        }
        return s;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)