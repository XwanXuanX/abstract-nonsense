#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        vector<int> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i)
            cin>>a[i];
        map<int,vector<int>> cnt;
        for(int i=0; i<n; ++i)
            cnt[a[i]].push_back(i);
        int sat=0;
        bool done=false;
        vector<int> ans(n);
        for(auto& p:cnt){
            if(p.second.size()>1){
                sat++;
                if(!done){
                    done=true;
                    ans[p.second[0]]=1;
                    for(int i=1; i<p.second.size(); ++i)
                        ans[p.second[i]]=2;
                }else{
                    ans[p.second[0]]=2;
                    for(int i=1; i<p.second.size(); ++i)
                        ans[p.second[i]]=3;
                }
            }else{
                ans[p.second[0]]=1;
            }
        }
        if(sat<2){
            cout<<-1<<'\n';
        }else{
            for(int i=0; i<n; ++i)
                cout<<ans[i]<<' ';
            cout<<'\n';
        }
    }
}