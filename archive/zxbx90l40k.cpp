#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if (n % 2 == 0) {
            cout<<-1<<'\n';
            continue;
        }
        vector<int> ans;
        for(int i=1; i<=n; i+=2){
            ans.push_back(i);
        }
        for(int i=2; i<=n; i+=2) {
            ans.push_back(i);
        }
        for(int i=0; i<n; ++i) {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}

/**
 * 4 1 3 5 2
 * the number after the current fix point must be greater than the current
 * number by 2 (3 -> 5)
 * 5 2 4 1 3
 * also note that the order of the number are not important
 * 5 7 2 4 6 1 3
 * 
 */