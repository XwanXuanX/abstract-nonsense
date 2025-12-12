#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].push_back(i);
            if (mp[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)