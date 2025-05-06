#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin>>s;
    if(s.size() < 2){cout<<-1<<endl; return;}
    for(int i=1; i<s.size(); ++i) if(s[i]==s[i-1]){cout<<s[i]<<s[i]<<endl; return;}
    for(int i=2; i<s.size(); ++i) if(s[i]!=s[i-1] && s[i]!=s[i-2] && s[i-1]!=s[i-2]){cout<<s[i-2]<<s[i-1]<<s[i]<<endl; return;}
    cout<<-1<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}