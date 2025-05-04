#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        vector<int> d;
        for(int i=0; i<n; ++i){
            d.push_back(abs(a[i]-(i+1)));
        }
        int g=d[0];
        for(int i=0; i<n; ++i){
            if(d[i]==0)
                continue;
            g=gcd(g,d[i]);
        }
        cout<<g<<'\n';
    }
}