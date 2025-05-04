#include <bits/stdc++.h>
using namespace std;
#define int long long

double calc(int x, int y){
    double S = x * y, P = 2 * x + 2 * y;
    return (P * P) / S;
}

void solve(){
    int n; cin>>n;
    vector<int> len(n);
    for(int i=0;i<n;++i) cin>>len[i];
    unordered_map<int,int> cnt;
    vector<int> pos;
    for(int i=0;i<n;++i) cnt[len[i]]++;
    for(auto& p:cnt){
        if(p.second >= 4){ for(int i=0;i<4;++i) cout<<p.first<<' '; cout<<endl; return; } // this is the best we can do!
        if(p.second >= 2) pos.push_back(p.first);
    }
    double ans = 1e9;
    int start = 0;
    sort(pos.begin(), pos.end());
    for(int i=1;i<pos.size();++i){
        double v = calc(pos[i], pos[i-1]);
        if(v < ans) start = i - 1, ans = v; 
    }
    cout<<pos[start]<<' '<<pos[start]<<' '<<pos[start+1]<<' '<<pos[start+1]<<endl;
}

/**
 * the closer the width and height of the rectangle the better
 * and you can see that the ratio converge to 16 eventually
 */

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();   
}