#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    int ans=0;

    // preproc
    int top_tot=0, bot_tot=0;
    for(int i=0; i<n; ++i) if(s[0][i]=='.') top_tot++;
    for(int i=0; i<n; ++i) if(s[1][i]=='.') bot_tot++;

    // top
    int lcnt=0;
    for(int i=0; i<n; ++i) if(s[0][i]=='.'){
        if(i>0 && s[1][i-1]=='x' && s[1][i+1]=='x' && s[1][i]=='.' && lcnt > 0 && (lcnt+1) < top_tot) ans++;
        lcnt++;
    }

    // bottom
    lcnt=0;
    for(int i=0; i<n; ++i) if(s[1][i]=='.'){
        if(i>0 && s[0][i-1]=='x' && s[0][i+1]=='x' && s[0][i]=='.' && lcnt > 0 && (lcnt+1) < bot_tot) ans++;
        lcnt++;
    }

    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}