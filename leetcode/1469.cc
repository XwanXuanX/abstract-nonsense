#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cs(26, 0), ct(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            cs[s[i] - 'a']++, ct[t[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += abs(cs[i] - ct[i]);
        }
        return ans / 2;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)