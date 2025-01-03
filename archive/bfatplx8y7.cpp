#include <bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>>& G,int& ans,string& s,
         int node,int acc){
    if(G[node].first==0&&G[node].second==0){
        ans=min(ans,acc);
        return;
    }
    // left
    if(G[node].first!=0){
        int nacc=(s[node]=='R'||s[node]=='U')?acc+1:acc;
        dfs(G,ans,s,G[node].first,nacc);
    }
    // right
    if(G[node].second!=0){
        int nacc=(s[node]=='L'||s[node]=='U')?acc+1:acc;
        dfs(G,ans,s,G[node].second,nacc);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string s;
        cin>>n>>s;
        s.insert(s.begin(),' ');
        vector<pair<int,int>> G(n+1);
        for(int i=1; i<=n; ++i)
            cin>>G[i].first>>G[i].second;
        int ans=INT_MAX;
        dfs(G,ans,s,1,0);
        cout<<ans<<'\n';
    }
}