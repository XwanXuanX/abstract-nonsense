#include <bits/stdc++.h>
using namespace std;
#define yetong_li_ ios_base::sync_with_stdio(0); cin.tie(0);

int n;
string s;
vector<int> a;

void solve(){
    cin>>n;
    a.assign(n,0);
    for(int i=0; i<n; ++i) cin>>a[i];
    cin>>s;

    for(int i=0; i<n; ++i) a[i]--;
    transform(s.begin(),s.end(),s.begin(),[](char c){return c-'0';});

    // if all array elements form a cycle, then ans = # of black ele
    // for each black ele, find the cycle that asso wth it, +1 for all ele in the cycle

    vector<int> ans(n,0);
    vector<int> cyc;
    vector<bool> vis(n, false);
    for(int i=0; i<n; ++i)
        if(!s[i] && !vis[i]){
            cyc.clear();
            int p=i;
            while(!vis[p]){
                cyc.push_back(p);
                vis[p]=true;
                p=a[p];
            }

            int valid=0;
            for(int j=0; j<cyc.size(); ++j)
                if(!s[cyc[j]])
                    valid++;
                
            for(int j=0; j<cyc.size(); ++j)
                ans[cyc[j]]=valid;
        }
    
    for(int i=0; i<n; ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
}

signed main(){
    yetong_li_
    int t; cin>>t;
    while(t--) solve();
}