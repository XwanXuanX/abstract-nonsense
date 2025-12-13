#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int balancedString(string s) {
        const int n = s.size(), expect = n / 4;
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; ++i) {
            cnt[s[i]]++;
        }
        for (auto& cs : {'Q', 'W', 'E', 'R'}) {
            if (cnt[cs] <= expect) {
                cnt.erase(cs);
            } else {
                cnt[cs] -= expect;
            }
        }
        if (cnt.size() == 0) {
            return 0;
        }
        unordered_map<char, int> cnt2;
        auto check = [&]() {
            for (const auto& p : cnt) {
                if (p.second > cnt2[p.first]) {
                    return false;
                }
            }
            return true;
        };
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n; ++r) {
            cnt2[s[r]]++;
            while (check()) {
                ans = min(ans, r - l + 1);
                cnt2[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)