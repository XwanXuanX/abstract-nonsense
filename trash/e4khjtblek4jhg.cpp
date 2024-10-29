/**
 * 1 2 3
 * 1 2 3 4 5 6
 * so for any starting position, we find the ending position
 * remove the ending that is associated with the start that has been checked
 * 
 * IT'S NOT WORKING!
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,a,b;
    cin>>n>>m;
    map<int,vector<int>> prs;
    map<int,int> ending;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        int start=min(a,b), end=max(a,b);
        prs[start-1].push_back(end-1);
        ending[end-1]++;
    }

    int ans=0;
    for(int i=0;i<n;++i){
        auto it=ending.upper_bound(i);
        if(it==ending.end()){ // include the rest list as answer
            int sz=n-i;
            ans+=(((sz * (sz+1)) / 2) - sz);
            break;
        }
        int ed=(*it).first, sz=ed-i;
        ans+=(((sz * (sz+1)) / 2) - sz);
        // remove the ending associated with the start
        for(auto e:prs[i]){
            ending[e]--;
            if(ending[e]==0)
                ending.erase(e);
        }
    }

    ans+=n;
    cout<<ans<<endl;
    return;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}
