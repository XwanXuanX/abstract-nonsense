#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<vector<int>> even(n,vector<int>(26,0)),
        odd(n,vector<int>(26,0));
    for(int i=0; i<n; i+=2){
        even[i][s[i]-'a']=1;
    }
    for(int i=1; i<n; i+=2){
        odd[i][s[i]-'a']=1;
    }
    for(int i=0; i<26; ++i){
        for(int j=1; j<n; ++j){
            even[j][i]+=even[j-1][i];
            odd[j][i]+=odd[j-1][i];
        }
    }
    if(n%2==0){
        int mxe=0,mxo=0;
        for(int i=0; i<26; ++i){
            mxe=max(mxe,even[n-1][i]);
            mxo=max(mxo,odd[n-1][i]);
        }
        cout<<(n/2)-mxe+(n/2)-mxo<<'\n';
        return;
    }
    int ans=INT_MAX;
    for(int i=0; i<n; ++i){
        int mxe=0,mxo=0;
        for(int j=0; j<26; ++j){
            mxe=max(mxe,((i>0)?even[i-1][j]:0)+odd[n-1][j]-odd[i][j]);
            mxo=max(mxo,((i>0)?odd[i-1][j]:0)+even[n-1][j]-even[i][j]);
        }
        int nn=(n-1)/2;
        ans=min(ans,nn-mxe+nn-mxo);
    }
    cout<<ans+1<<'\n';
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

// if n is even, then it's very easy
// if n is odd, then you must delete one char, makes the following chars shifts even and odd
// 0 1 2 3 4 5 6 7 8