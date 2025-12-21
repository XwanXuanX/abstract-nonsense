#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxRepOpt1(string text) {
        const int n = text.size();
        vector<pair<int, int>> seg;
        int start = 0;
        for (int i = 1; i < n; ++i) {
            if (text[i] != text[i - 1]) {
                seg.push_back({start, i - 1});
                start = i;
            }
        }
        seg.push_back({start, n - 1});
        unordered_map<char, vector<pair<int, int>>> grp;
        for (auto& s : seg) {
            assert(text[s.first] == text[s.second]);
            grp[text[s.first]].push_back(std::move(s));
        }
        int ans = 0;
        for (const auto& [_, s] : grp) {
            for (const auto& p : s) {
                ans = max(ans, p.second - p.first + 1);
            }
            for (int i = 1; i < s.size(); ++i) {
                const auto& [a, b] = s[i - 1];
                const auto& [c, d] = s[i];
                const int l1 = b - a + 1, l2 = d - c + 1;
                if (b + 2 == c) {
                    ans = max(ans, l1 + l2 + (s.size() > 2));
                } else {
                    ans = max(ans, max(l1, l2) + 1);
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)