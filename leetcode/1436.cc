#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    unordered_map<int, vector<int>> G;

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        const int n = friends.size();
        for (int i = 0; i < n; ++i) {
            for (const auto& e : friends[i]) {
                G[i].push_back(e), G[e].push_back(i);
            }
        }
        queue<int> Q;
        Q.push(id);
        unordered_set<int> V;
        V.insert(id);
        int step = 0;
        vector<int> lvl;
        while (Q.size()) {
            const int sz = Q.size();
            for (int _ = 0; _ < sz; ++_) {
                const auto nod = Q.front();
                Q.pop();
                assert(V.count(nod));
                if (step == level)
                    lvl.push_back(nod);
                for (const auto& adj : G[nod]) {
                    if (!V.count(adj)) {
                        Q.push(adj);
                        V.insert(adj);
                    }
                }
            }
            if (step == level)
                break;
            step++;
        }
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (const auto f : lvl) {
            for (const auto& vid : watchedVideos[f])
            cnt[vid]++;
        }
        vector<pair<int, string>> _ans;
        for (const auto& p : cnt) {
            _ans.push_back({p.second, p.first});
        }
        sort(_ans.begin(), _ans.end());
        for (const auto& p : _ans) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)