/**
 * LDS is LIS in the other direction
 * n = 6 how can we construct the answer
 * 1 2 3 4 5 6  6 + 1
 * 3 6 4 5 1 2  3 + 3
 * 2 1 4 3 6 5
 * 2 1 3
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> ans(n + 1);
    int L = (int)sqrt(n);
    for(int i = 1, o = n; i <= n; i += L)
        for(int j = min(n, i+L-1); j >= i; ans[j--] = o--);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}