#include <bits/stdc++.h>
using namespace std;

int n,q;
string a,b;
const int N=26;
vector<int> cnta[N], cntb[N];

void solve(){
    cin>>n>>q>>a>>b;
    for(int i=0; i<N; ++i)
        cnta[i].assign(n+1,0), cntb[i].assign(n+1,0);
    for(int i=0; i<n; ++i)
        cnta[a[i]-'a'][i+1]++, cntb[b[i]-'a'][i+1]++;
    for(int i=0; i<N; ++i)
        for(int j=2; j<=n; ++j)
            cnta[i][j]+=cnta[i][j-1], cntb[i][j]+=cntb[i][j-1];
    for(int k=0; k<q; ++k){
        int l,r; cin>>l>>r;
        int sum=0;
        for(int i=0; i<N; ++i){
            int ca=cnta[i][r] - cnta[i][l-1];
            int cb=cntb[i][r] - cntb[i][l-1];
            sum += abs(ca-cb);
        }
        cout<<sum/2<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}