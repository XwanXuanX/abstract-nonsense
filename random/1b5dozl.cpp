#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve(){
    cin>>n>>s;
    int cnt=0;
    for(int i=0; i<n; ++i)
        if(s[i]=='1')
            cnt++;
    if(cnt%2){
        cout<<"NO\n";
        return;
    }

    // the only dangerous case is cnt=2 and two adjcent 1s
    if(cnt==2){
        vector<int> pos;
        for(int i=0; i<n; ++i)
            if(s[i]=='1')
                pos.push_back(i);
        if(pos[0]+1 == pos[1]){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}