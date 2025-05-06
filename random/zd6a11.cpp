#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        vector<pair<int,int>> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i){
            cin>>a[i].first;
            a[i].second=i+1;
        }
        sort(a.begin(),a.end());
        vector<pair<int,int>> ans;
        for(int i=1; i<n; ++i){
            if(a[i].first>a[i-1].first){
                int mod=a[i].first%a[i-1].first;
                if(mod){
                    int inc=a[i-1].first-mod;
                    a[i].first+=inc;
                    ans.push_back(make_pair(a[i].second,inc));
                }
            }else if(a[i].first<a[i-1].first){
                int inc=a[i-1].first-a[i].first;
                a[i].first+=inc;
                ans.push_back(make_pair(a[i].second,inc));
            }
        }
        cout<<ans.size()<<'\n';
        for(auto[i,p]:ans){
            cout<<i<<' '<<p<<'\n';
        }
    }
}