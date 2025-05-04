#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int k,n;
        cin>>k>>n;
        vector<int> a{1,2};
        int diff=n-k,tot=0;
        for(int i=2; i<n&&a.size()<k; ++i){
            tot+=(i-1);
            if(diff-tot<0){
                break;
            }
            a.push_back(a[i-1]+i);
        }
        while(a.size()<k){
            a.push_back(a.back()+1);
        }
        for(int i=0; i<a.size(); ++i){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}