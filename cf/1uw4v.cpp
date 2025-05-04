#include <bits/stdc++.h>
using namespace std;

set<pair<int,int>> all(int x,int y,int a,int b){
    set<pair<int,int>> com;
    com.insert(make_pair(x+a,y+b));
    com.insert(make_pair(x+a,y-b));
    com.insert(make_pair(x-a,y+b));
    com.insert(make_pair(x-a,y-b));
    com.insert(make_pair(x+b,y+a));
    com.insert(make_pair(x+b,y-a));
    com.insert(make_pair(x-b,y+a));
    com.insert(make_pair(x-b,y-a));
    return com;
}

void solve(){
    int a,b,xk,yk,xq,yq;
    cin>>a>>b>>xk>>yk>>xq>>yq;
    auto p1=all(xk,yk,a,b);
    auto p2=all(xq,yq,a,b);
    int ans=0;
    for(auto& p:p1){
        if(p2.count(p))
            ans++;
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