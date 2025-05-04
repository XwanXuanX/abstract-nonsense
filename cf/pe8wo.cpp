#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    transform(s.begin(),s.end(),s.begin(),[](char c){return c-'0';});
    int q; cin>>q;
    int n=s.size(), cnt=0;
    for(int i=3; i<n; ++i)
        if(s[i-3] && s[i-2] && !s[i-1] && !s[i])
            cnt++;
    for(int i=0; i<q; ++i){
        int x,v; cin>>x>>v; x--;
        // before update
        bool before, after;
        if((!s[x] && ((x>=3 && s[x-3] && s[x-2] && !s[x-1] && !s[x]) || (x>=2 && x<=n-2 && s[x-2] && s[x-1] && !s[x] && !s[x+1]))) ||
            (s[x] && ((x<=n-4 && s[x] && s[x+1] && !s[x+2] && !s[x+3]) || (x<=n-3 && x>0 && s[x-1] && s[x] && !s[x+1] && !s[x+2]))))
            before = true; else before = false;
        // after update
        s[x] = (char)v;
        if((!s[x] && ((x>=3 && s[x-3] && s[x-2] && !s[x-1] && !s[x]) || (x>=2 && x<=n-2 && s[x-2] && s[x-1] && !s[x] && !s[x+1]))) ||
            (s[x] && ((x<=n-4 && s[x] && s[x+1] && !s[x+2] && !s[x+3]) || (x<=n-3 && x>0 && s[x-1] && s[x] && !s[x+1] && !s[x+2]))))
            after = true; else after = false;
        if(before && !after) cnt--;
        if(!before && after) cnt++;
        if(cnt>0) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}