#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    unordered_map<int, vector<int>> G;

    int removeStones(const vector<vector<int>>& stones) {
        const int n = stones.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                const auto& node1 = stones[i], &node2 = stones[j];
                if (node1[0] == node2[0] || node1[1] == node2[1]) {
                    G[i].push_back(j), G[j].push_back(i);
                }
            }
        }
        unordered_set<int> V;
        function<void(const int node, int& size)> dfs;
        dfs = [&](const int node, int& size) {
            assert(!V.count(node));
            V.insert(node);
            size++;
            for (const auto& adj : G[node]) {
                if (!V.count(adj)) {
                    dfs(adj, size);
                }
            }
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!V.count(i)) {
                int size = 0;
                dfs(i, size);
                ans += size - 1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)