#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int h, n; cin >> h >> n;
    vector<int> a(n), c(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> c[i];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 0; i < n; ++i)
        pq.push(make_pair(1, i));
    int time = 0;
    while(h > 0){
        time = pq.top().first;
        while(pq.top().first == time){
            auto p = pq.top(); pq.pop();
            h -= a[p.second];
            pq.push(make_pair(time + c[p.second], p.second));
        }
    }
    cout << time << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}