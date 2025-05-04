#include <bits/stdc++.h>
using namespace std;

vector<int> getDigs(int n) {
    vector<int> digs;
    while (n) {
        digs.push_back(n % 10);
        n /= 10;
    }
    return digs;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        vector<int> digs = getDigs(i);
        for (int d : digs) {
            dp[i] = min(dp[i], dp[i - d]);
        }
        dp[i]++;
    }
    cout << dp[n] << '\n';
}