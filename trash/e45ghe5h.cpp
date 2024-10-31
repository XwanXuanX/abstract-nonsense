#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    vector<int> buf;
    for(int i=0;i<n;++i)
        cin>>a, buf.push_back(a);
    int m,w,h;
    cin>>m;
    int prev=0;
    while(m--){
        cin>>w>>h;
        prev=max(prev, buf[w-1]) + h;
        cout<<prev-h<<endl;
    }
    return 0;
}