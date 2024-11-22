#include <bits/stdc++.h>
using namespace std;
#define int long long 

set<int> factor(int n){
    set<int> pf;
    for(int i=2;i*i<=n;++i){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            pf.insert(i);
        }
    }
    if(n > 1) pf.insert(n);
    return pf;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b; cin>>n;
    vector<pair<int,int>> pr;
    for(int i=0;i<n;++i) cin>>a>>b, pr.push_back(make_pair(a, b));
    set<int> pfa = factor(a), pfb = factor(b), all;
    set_union(pfa.begin(), pfa.end(), pfb.begin(), pfb.end(), inserter(all, all.begin()));
    for(auto d:all){
        bool ok = true;
        for(int i=0;i<n-1;++i)
            if(pr[i].first % d && pr[i].second % d){ ok = false; break; }
        if(ok){ cout<<d<<endl; return 0; }
    }
    cout<<-1<<endl;
    return 0;
}