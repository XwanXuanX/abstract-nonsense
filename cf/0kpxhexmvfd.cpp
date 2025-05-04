#include <bits/stdc++.h>
using namespace std;

int diff(string& s,string& t){
    int cnt=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]!=t[i])
            cnt++;
    }
    return cnt;
}

void solve(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    if(s==t){
        cout<<0<<'\n';
        return;
    }
    int a=diff(s,t);
    reverse(s.begin(),s.end());
    int b=diff(s,t);
    if(min(a,b)==0){
        cout<<2<<'\n';
        return;
    }
    int ans=INT_MAX;
    ans=min(ans,2*b-((b-1)%2));
    ans=min(ans,2*a-(!((a-1)%2)));
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

// note that reverse one string is equal to reverse two
// replace one string is equal to replace two