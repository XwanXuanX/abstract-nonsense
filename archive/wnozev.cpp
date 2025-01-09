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
        for(int i=0; i<n-2; i+=2){
            a[i]=abs(a[i]);
            a[i+1]=-abs(a[i+1]);
        }
        a[n-1]=abs(a[n-1]);
        for(int i=0; i<n; ++i)
            cout<<a[i]<<' ';
        cout<<'\n';
    }
}