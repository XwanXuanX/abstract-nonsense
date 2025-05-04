#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while (tt--) {
        int n, k;
        cin>>n>>k;
        vector<int> l(n), r(n);
        for (int i=0; i<n; ++i) {
            cin>>l[i];
        }
        for (int i=0; i<n; ++i) {
            cin>>r[i];
        }
        int worst = 0;
        vector<int> fine;
        for (int i=0; i<n; ++i) {
            worst += max(l[i], r[i]);
            fine.push_back(min(l[i], r[i]));
        }
        sort(fine.rbegin(), fine.rend());
        for (int i=0; i<k-1; ++i) {
            worst += fine[i];
        }
        cout<<worst + 1<<'\n';
    }
}

/**
 * of course, the answer should be greater than the sum of all l and r
 * so clearly we need to take the largest one
 */