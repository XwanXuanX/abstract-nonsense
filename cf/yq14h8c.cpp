#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) {
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        set<int> cnt;
        for (int i=0; i<n; ++i) {
            cin>>a[i];
            cnt.insert(a[i]);
        }
        // if too many distinct values
        if (cnt.size() > k) {
            cout<<-1<<'\n';
            continue;
        }
        // to construct the answer, we generate k distinct elements
        // and stamp the sequence over and over again!
        int cut = 1;
        while (cnt.size() < k) {
            cnt.insert(cut++);
        }
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            for (auto j : cnt) {
                ans.push_back(j);
            }
        }
        cout<<ans.size()<<'\n';
        for (int i=0; i<ans.size(); ++i) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}

/**
 * 1 2 3
 * 1 2 1 2 1 3 ... not possible for this case
 * 4 3 4 2 4 3 4
 * seems to me that it has something to do with the number of distinct values:
 * if the number of distinct values is not more than k, then we can definitely
 * generate a sequence for it; otherwise, no.
 * 1 2 2 1
 * 1 2 3 1 2 3 1
 */