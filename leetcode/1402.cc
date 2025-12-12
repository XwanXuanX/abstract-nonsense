#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pfs(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pfs[i][j] = matrix[i][j];
                if (i > 0)
                    pfs[i][j] += pfs[i - 1][j];
                if (j > 0)
                    pfs[i][j] += pfs[i][j - 1];
                if (i > 0 && j > 0)
                    pfs[i][j] -= pfs[i - 1][j - 1];
            }
        }
        auto qr = [&](const int r1, const int c1, const int r2, const int c2) {
            const int total = pfs[r2][c2];
            const int top = (r1 > 0) ? pfs[r1 - 1][c2] : 0;
            const int left = (c1 > 0) ? pfs[r2][c1 - 1] : 0;
            const int overlap = (r1 > 0 && c1 > 0) ? pfs[r1 - 1][c1 - 1] : 0;
            return total - top - left + overlap;
        };
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int l = 0, r = 300, res = -1;
                while (l <= r) {
                    const int mid = (l + r) >> 1;
                    if (i + mid >= n || j + mid >= m || qr(i, j, i + mid, j + mid) < (mid + 1) * (mid + 1)) {
                        r = mid - 1;
                    } else {
                        res = max(res, mid);
                        l = mid + 1;
                    }
                }
                ans += res + 1;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)