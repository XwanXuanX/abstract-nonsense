#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stk;
        for (const auto c : s) {
            if (stk.empty()) {
                stk.push({c, 1});
            } else {
                if (c == stk.top().first) {
                    if (stk.top().second + 1 == k) {
                        stk.pop();
                    } else {
                        stk.top().second++;
                    }
                } else {
                    stk.push({c, 1});
                }
            }
        }
        string ans;
        while (stk.size()) {
            const auto [c, cnt] = stk.top();
            stk.pop();
            for (int i = 0; i < cnt; ++i) {
                ans.push_back(c);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)