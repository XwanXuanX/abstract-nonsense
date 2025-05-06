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
    
    // check if all elements are even
    bool ae=true;
    for(int i=0; i<n; ++i)
        if(a[i]%2!=0)
            ae=false;
    if(ae){
        cout<<0<<'\n';
        return;
    }

    // if one element is odd, the entire array must be odd
    vector<int> even;
    for(int i=0; i<n; ++i)
        if(a[i] % 2 == 0) even.push_back(a[i]);
    if(even.size()==0){
        cout<<0<<'\n';
        return;
    }
    sort(even.begin(),even.end());

    int mx=0;
    for(int i=0; i<n; ++i)
        if(a[i] % 2) mx=max(mx,a[i]);
    if(even[0] > mx){
        cout<<even.size()+1<<'\n';
        return;
    }
    even[0] += mx;

    for(int i=1; i<even.size(); ++i){
        if(even[i-1] < even[i]){
            cout<<even.size()+1<<'\n';
            return;
        }
        even[i] += even[i-1];
    }

    cout<<even.size()<<'\n';
}

// 3 2 2 8
// 11 2 2 8
// you need to make an odd number bigger than the biggest even number

signed main(){
    int t; cin>>t;
    while(t--) solve();
}