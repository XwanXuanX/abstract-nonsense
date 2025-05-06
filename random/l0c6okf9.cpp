#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<'\n';
            continue;
        }
        cout<<6;
        for(int i=0; i<n-1; ++i)
            cout<<7;
        cout<<'\n';
    }
}