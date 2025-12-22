#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<string> printVertically(string s) {
        int longest = 0, curr = 0, word = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                word++;
                longest = max(longest, curr);
                curr = 0;
            } else
                curr++;
        }
        longest = max(longest, curr);
        vector<string> ans(longest);
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                ans[j++].push_back(s[i]);
            } else {
                while (j != ans.size())
                    ans[j++].push_back(' ');
                j = 0;
            }
        }
        for (int i = 0; i < longest; i++) {
            if (ans[i].back() == ' ') {
                while (!ans[i].empty() && ans[i].back() == ' ')
                    ans[i].pop_back();
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)