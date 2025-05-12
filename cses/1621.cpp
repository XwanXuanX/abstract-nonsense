#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        a.insert(in);
    }

    cout << a.size() << '\n';
}