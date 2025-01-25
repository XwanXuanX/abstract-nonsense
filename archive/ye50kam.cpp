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
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        set<int> unused;
        for(int i=1; i<=n; ++i){
            unused.insert(i);
        }
        vector<int> ans(n);
        for(int i=0; i<n; ++i){
            if(unused.count(a[i])){
                unused.erase(a[i]);
                ans[i]=a[i];
            }else{
                ans[i]=*(unused.begin());
                unused.erase(unused.begin());
            }
        }
        for(int i=0; i<n; ++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}