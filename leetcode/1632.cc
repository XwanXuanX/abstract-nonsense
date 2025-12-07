#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        unordered_map<char, int> lc, rc;
        for (auto c : s) {
            rc[c]++;
        }
        for (auto c : s) {
            rc[c]--;
            if (rc[c] == 0)
                rc.erase(c);
            lc[c]++;
            if (lc.size() == rc.size())
                ans++;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)