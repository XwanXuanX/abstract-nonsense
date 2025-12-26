#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int bestClosingTime(const string customers) {
        const int n = customers.size();
        int mn = 1e9, ans = 1e9;
        vector<int> N(n, 0), Y(n, 0);
        N[0] = customers[0] == 'N';
        Y[n - 1] = customers[n - 1] == 'Y';
        for (int i = 1; i < n; ++i) N[i] = N[i - 1] + (customers[i] == 'N');
        for (int i = n - 2; i >= 0; --i) Y[i] = Y[i + 1] + (customers[i] == 'Y');
        for (int i = 0; i <= n; ++i) {
            const int l = i == 0 ? 0 : N[i - 1];
            const int r = i == n ? 0 : Y[i];
            if (l + r < mn) {
                mn = l + r;
                ans = i;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)