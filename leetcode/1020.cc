#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int n = arr.size();
        if (n == 1) return 1;
        vector<int> comp;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                comp.push_back(0);
            } else if (arr[i] < arr[i - 1]) {
                comp.push_back(1);
            } else {
                comp.push_back(-1);
            }
        }
        vector<pair<int, int>> seg;
        int start = 0, ans = 1;
        for (int i = 1; i < comp.size(); ++i) {
            if (comp[i] == comp[i - 1] || comp[i - 1] == -1 || comp[i] == -1) {
                seg.push_back({start, i - 1});
                start = i;
            }
        }
        seg.push_back({start, comp.size() - 1});
        for (const auto& p : seg) {
            if (comp[p.first] != -1)
                ans = max(ans, p.second - p.first + 2);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)