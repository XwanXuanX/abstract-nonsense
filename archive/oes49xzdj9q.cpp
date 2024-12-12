#include <bits/stdc++.h>
using namespace std;
#define int long long

int dist(int x1, int y1, int x2, int y2){
    int dx=x2-x1, dy=y2-y1;
    return dx*dx + dy*dy;
}

void solve(){
    int n,a,b; cin>>n;
    vector<pair<int,int>> circ;
    for(int i=0; i<n; ++i)
        cin>>a>>b, circ.push_back(make_pair(a,b));
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    int need=dist(x1,y1,x2,y2); // it's better to walk straight
    for(int i=0; i<n; ++i){
        int tak=dist(circ[i].first, circ[i].second, x2, y2);
        if(tak <= need){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}