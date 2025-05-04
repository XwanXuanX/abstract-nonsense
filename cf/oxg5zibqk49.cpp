#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> a;

void solve(){
    cin>>n;
    a.assign(n,0);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    
    int odd=0, even=0;
    for(int i=0; i<n; i+=2)
        odd += a[i];
    for(int i=1; i<n; i+=2)
        even += a[i];
    
    int e=n/2;
    int o=ceil((double)n/2);

    if(odd%o || even%e || odd/o != even/e)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}