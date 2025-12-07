#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        for (auto& p : possible) {
            if (p == 0)
                p = -1;
        }
        int bob = 0, ali = 0;
        for (auto& p : possible) {
            bob += p;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; ++i) {
            const auto p = possible[i];
            bob -= p, ali += p;
            if (ali > bob)
                ans = min(ans, i + 1);
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)