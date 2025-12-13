#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        const int n = colsum.size();
        int up = upper, lo = lower, n1 = 0;
        for (const auto& s : colsum) {
            if (s == 2) {
                up--, lo--;
            } else if (s == 1) {
                n1++;
            }
        }
        if (up < 0 || lo < 0 || up + lo != n1) {
            return {};
        }
        vector<vector<int>> ans(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (up) ans[0][i] = 1, up--;
                else if (lo) ans[1][i] = 1, lo--;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)