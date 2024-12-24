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
        
    int acc=0;
    vector<int> ok;
    for(int i=0; i<n; ++i){
        if(s[i]=='1')
            acc++;
        
        int l=i+1, r=n-i-1;
        // check if the current cut off point is valid
        int lth=ceil((double)l / 2), rth=ceil((double)r / 2);
        if((l-acc >= lth) && (cnt-acc >= rth))
            ok.push_back(i);
    }

    if(ok.size()==0){
        cout<<0<<'\n';
        return;
    }

    double mn=1e9, ans=0;
    for(int i=0; i<ok.size(); ++i){
        if(abs((double)n/2 - (ok[i]+1)) < mn){
            mn = abs((double)n/2 - (ok[i]+1));
            ans = ok[i]+1;
        }
    }

    if(cnt == n-cnt && ans == n)
        cout<<0<<'\n';
    else
        cout<<ans<<'\n';
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}