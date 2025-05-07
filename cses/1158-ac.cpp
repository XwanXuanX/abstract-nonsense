#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> h(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    
    // vector<vector<int>> mm(x + 1, vector<int>(n + 1, 0));
    vector<int> mm(x + 1, 0);
    // note that the row is the item, the columns are money
    for (int j = 1; j <= n; ++j) {
        for (int i = x; i >= h[j]; --i) {
            mm[i] = max(mm[i - h[j]] + s[j], mm[i]);
        }
    }

    printf("%d\n", mm[x]);
}