#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, unordered_set<string>> G;
        vector<string> result(1);
        for (const auto& p : synonyms) {
            G[p[0]].insert(p[1]), G[p[1]].insert(p[0]);
        }
        stringstream ss(text);
        string word;
        while (ss >> word) {
            queue<string> Q({word});
            vector<string> res;
            unordered_set<string> V;
            V.insert(word);
            while (Q.size()) {
                const auto node = Q.front();
                Q.pop();
                for (auto& s : result) {
                    res.push_back(s + node + " ");
                }
                for (const auto& adj : G[node]) {
                    if (!V.count(adj)) {
                        V.insert(adj);
                        Q.push(adj);
                    }
                }
            }
            result.swap(res);
        }
        sort(result.begin(), result.end());
        for (auto& s : result) {
            s.pop_back();
        }
        return result;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)