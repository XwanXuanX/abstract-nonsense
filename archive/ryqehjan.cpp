#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        vector<int> a;
        cin>>n>>k;
        a.resize(n);
        for(int i=0; i<n; ++i)
            cin>>a[i];
        vector<set<int>> A(k);
        for(int j=0; j<k; ++j){
            for(int i=j; i<n; i+=k){
                A[j].insert(a[i]);
            }
        }
        int ans=0;
        for(int j=0; j<k; ++j){
            for(int i=j; i<n; i+=k){
                if(!A[j].count(i+1))
                    ans++;
            }
        }
        if(ans==0){
            cout<<0<<'\n';
        }else if(ans==2){
            cout<<1<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
}