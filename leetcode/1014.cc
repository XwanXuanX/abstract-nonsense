#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto dist = [](const vector<int>& a, const vector<int>& b) -> ll {
            return static_cast<ll>(a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
        };
        const int n = points.size();
        vector<pair<ll, vector<int>>> a;
        for (const auto& p : points) {
            a.push_back({dist(p, {0, 0}), p});
        }
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(a[i].second);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)