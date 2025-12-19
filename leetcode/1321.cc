#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        const int n = s.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(s[i] - t[i]);
        }
        int tot = 0, ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            tot += diff[r];
            while (tot > maxCost) {
                tot -= diff[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)