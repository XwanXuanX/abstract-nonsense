#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maximumSum(vector<int> &arr) {
        arr.insert(arr.begin(), 0);
        const int n = arr.size();
        vector<int> pfs(n, 0);
        for (int i = 1; i < n; ++i) {
            pfs[i] = pfs[i - 1] + arr[i];
        }
        vector<int> mx(n, -1e9), mn(n, 1e9);
        mn[0] = min(mn[0], pfs[0]);
        for (int i = 1; i < n; ++i) {
            mn[i] = min(mn[i], min(pfs[i], mn[i - 1]));
        }
        mx[n - 1] = max(mx[n - 1], pfs[n - 1]);
        for (int i = n - 2; i >= 0; --i) {
            mx[i] = max(mx[i], max(pfs[i], mx[i + 1]));
        }
        int ans = -1e9;
        for (int i = 1; i < n - 1; ++i) {
            if (arr[i] < 0) {
                const int mmn = mn[i - 1], mmx = mx[i + 1] + abs(arr[i]);
                ans = max(ans, mmx - mmn);
            }
        }
        for (int i = 1; i < n; ++i) {
            const int mmn = mn[i - 1], mmx = mx[i];
            ans = max(ans, mmx - mmn);
        }
        return ans;
    }
};

//IMPORTANT!! Submit Code Region End(Do not remove this line)
