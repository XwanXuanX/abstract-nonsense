#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minSwaps(vector<int>& data) {
        const int n = data.size();
        int n1 = 0, n0 = 0, ans = 1e9;
        for (const auto d : data) {
            n1 += d;
        }
        for (int i = 0; i < n1; ++i) {
            if (!data[i]) {
                n0 += 1;
            }
        }
        ans = min(ans, n0);
        for (int l = 1, r = n1; r < n; ++r, ++l) {
            if (!data[r]) {
                n0 += 1;
            }
            if (!data[l - 1]) {
                n0 -= 1;
            }
            ans = min(ans, n0);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)