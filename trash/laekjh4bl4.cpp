#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> f(n), b(m);
    for(int i=0;i<n;++i)
        cin>>f[i];
    for(int i=0;i<m;++i)
        cin>>b[i];
    
    // if b contains something that f does not have, then impossible
    set<int> sf(f.begin(), f.end());
    for(int i=0;i<b.size();++i)
        if(!sf.count(b[i])){
            cout<<"Impossible"<<endl;
            return 0;
        }
    
    // otherwise, we can surely obtain the original sequence
    map<int,vector<int>> lut;
    for(int i=0;i<f.size();++i)
        lut[f[i]].push_back(i+1);
    
    bool amb=false;
    vector<int> ans(m);
    for(int i=0;i<m;++i){
        if(lut[b[i]].size() > 1){
            amb=true;
            break;
        }
        ans[i] = lut[b[i]].front();
    }

    if(amb){
        cout<<"Ambiguity"<<endl;
    }else{
        cout<<"Possible"<<endl;
        for(int i=0;i<ans.size();++i)
            cout<<ans[i]<<' ';
        cout<<endl;
    }

    return 0;
}