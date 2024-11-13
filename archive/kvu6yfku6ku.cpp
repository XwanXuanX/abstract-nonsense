#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    // we cannot place more than one point per col or per row
    // so the answer is upper bounded by the minimum dimension
    int bnd=min(n,m);
    set<pair<int,int>> ans;
    // to construct the answer, we just need to place the points on the diagonals (the other one, sure duh)
    for(int i=0;i<=bnd;++i)
        ans.insert(make_pair(i,bnd-i));
    // print()
    cout<<ans.size()<<endl;
    for(auto& p:ans)
        cout<<p.first<<' '<<p.second<<endl;
    return 0;
}