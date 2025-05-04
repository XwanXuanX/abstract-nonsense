#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve(){
    cin>>n;
    a.assign(n,0);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    
    for(int i=0; i<n-1; ++i){
        if(a[i] == i+1)
            continue;

        if(abs(a[i]-(i+1)) > 1 || abs(a[i+1]-(i+2)) > 1 || a[i]+a[i+1] != (2*i + 3)){
            cout<<"NO\n";
            return;
        }else{
            ++i;
        }
    }

    cout<<"YES\n";
}

// it can be seen that we can only achieve permutation if only neighboring
// elements are swapped.

signed main(){
    int t; cin>>t;
    while(t--) solve();
}