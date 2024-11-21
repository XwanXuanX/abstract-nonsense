#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r; cin>>n;
    vector<int> start(n), end(n);
    vector<pair<int,int>> segment;
    for(int i=0;i<n;++i) cin>>start[i]>>end[i], segment.push_back(make_pair(start[i], end[i]));
    sort(start.begin(), start.end()); sort(end.begin(), end.end());
    int ans = 0;
    for(auto[l, r] : segment){
        if(l == start.back() && r == end.front()) ans = max(ans, end[1] - start[start.size()-2]);
        else if(l == start.back()) ans = max(ans, end[0] - start[start.size()-2]);
        else if(r == end.front()) ans = max(ans, end[1] - start[start.size()-1]);
    }
    cout<<ans<<endl;
    return 0;
}