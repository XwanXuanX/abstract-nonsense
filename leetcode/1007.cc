#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static vector<int> numsSameConsecDiff(int n, int k) {
        vector<vector<int>> nums;
        for (int i = 0; i <= 9; ++i) {
            nums.push_back({i});
        }
        for (int l = 1; l < n; ++l) {
            vector<vector<int>> _nums;
            for (auto digs : nums) {
                const auto last = digs.back();
                if (last + k <= 9) {
                    digs.push_back(last + k);
                    _nums.push_back(digs);
                    digs.pop_back();
                }
                if (last - k >= 0) {
                    digs.push_back(last - k);
                    _nums.push_back(digs);
                    digs.pop_back();
                }
            }
            nums.swap(_nums);
        }
        unordered_set<int> ans;
        for (auto& nn : nums) {
            reverse(nn.begin(), nn.end());
            if (nn.front() == 0) continue;
            int cons = 0;
            for (const auto d : nn) {
                cons = cons * 10 + d;
            }
            ans.insert(cons);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)