#include <bits/stdc++.h>
using namespace std;

void pad(string& l, string& s){
    while(s.size()<l.size()){
        s.insert(s.begin(),'0');
    }
}

void solve(){
    string s,t;
    cin>>s>>t;
    if(s.size()<t.size()){
        pad(t,s);
    }else{
        pad(s,t);
    }
    int n=s.size();
    string a,b;
    for(int i=0; i<n; ++i){
        a.push_back(t[i]);
        b.push_back(s[i]);
        if(t[i]>s[i])
            break;
    }
    while(a.size()<n){
        a.push_back('0');
        b.push_back('9');
    }
    int ans=0;
    for(int i=0; i<n; ++i){
        ans+=abs(a[i]-b[i]);
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}

// 55157581939688863366
// 54943329752812629795
// 55090909090909090909
// 54909090909090909090