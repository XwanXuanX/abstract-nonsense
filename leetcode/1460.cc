#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.size();
        int ans = 0;
        int cnt[3] = {0};
        auto valid = [&]() {
            return cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0;
        };
        for (int l = 0, r = 0; r < n; ++r) {
            cnt[s[r] - 'a']++;
            while (l < r && valid()) {
                cnt[s[l] - 'a']--;
                l++;
            }
            // [0 ... l - 1] is all valid
            ans += l;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)