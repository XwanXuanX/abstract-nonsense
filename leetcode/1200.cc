#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        for (const auto& in : intervals) {
            if (toBeRemoved[0] <= in[0] && in[1] <= toBeRemoved[1]) {
                continue;
            }
            if (in[0] <= toBeRemoved[0] && toBeRemoved[1] <= in[1]) {
                ans.push_back({in[0], toBeRemoved[0]});
                ans.push_back({toBeRemoved[1], in[1]});
            } else if (in[0] <= toBeRemoved[0] && toBeRemoved[0] <= in[1]) {
                ans.push_back({in[0], toBeRemoved[0]});
            } else if (in[0] <= toBeRemoved[1] && toBeRemoved[1] <= in[1]) {
                ans.push_back({toBeRemoved[1], in[1]});
            } else {
                ans.push_back(in);
            }
        }
        vector<vector<int>> _ans;
        for (const auto& v : ans) {
            if (v[0] != v[1]) {
                _ans.push_back(v);
            }
        }
        return _ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)