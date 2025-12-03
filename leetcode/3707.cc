#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> cnt;
        for (auto& r : responses) {
            unordered_set<string> unq(r.begin(), r.end());
            for (auto& s : unq) {
                cnt[s]++;
            }
        }
        string ans;
        int mx = 0;
        for (auto& p : cnt) {
            if (p.second > mx) {
                ans = p.first;
                mx = p.second;
            } else if (p.second == mx) {
                ans = min(ans, p.first);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)