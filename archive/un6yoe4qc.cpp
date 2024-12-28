#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& a, int t){
    for(int i=0; i<a.size(); ++i){
        if(a[i]==t)
            return i+1;
    }
    return -1;
}

void solve(){
    int n;
    vector<int> a;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int p1=find(a,1);
    int p2=find(a,2);
    int pn=find(a,n);
    if((p1>pn&&pn>p2) || (p1<pn&&pn<p2)){
        cout<<1<<' '<<1<<'\n';
        return;
    }
    if((p1>pn&&p1>p2) || (p1<pn&&p1<p2)){
        cout<<p2<<' '<<pn<<'\n';
        return;
    }
    cout<<p1<<' '<<pn<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}

// key note: if we can seperate 1 and 2 with n in between
// then we effectively results in only 2 permutations
// 2 1 n and n 1 2