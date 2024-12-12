#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
string s;

void solve(){
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    cin>>s;

    for(int i=1; i<n; ++i)
        a[i]+=a[i-1];
    
    int l=0, r=n-1, sum=0;
    while(l<r){
        if(s[l]=='L' && s[r]=='R'){
            sum += (a[r] - ((l==0) ? 0 : a[l-1]));
            l++, r--;
        }else{
            if(s[l]!='L') l++;
            if(s[r]!='R') r--;
        }
    }

    cout<<sum<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}