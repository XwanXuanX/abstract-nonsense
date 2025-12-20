#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        const int n = phrases.size();
        vector<vector<string>> words;
        for (const auto& p : phrases) {
            vector<string> ws;
            stringstream ss(p);
            string tok;
            while (getline(ss, tok, ' ')) {
                ws.push_back(tok);
            }
            words.push_back(std::move(ws));
        }
        set<string> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                const auto& li = words[i].back(), fj = words[j].front();
                if (i == j || li != fj) {
                    continue;
                }
                vector<string> puz = words[i];
                for (int k = 1; k < words[j].size(); ++k) {
                    puz.push_back(words[j][k]);
                }
                string can;
                for (int k = 0; k < puz.size(); ++k) {
                    can += puz[k] + ' ';
                }
                can.pop_back();
                ans.insert(can);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)