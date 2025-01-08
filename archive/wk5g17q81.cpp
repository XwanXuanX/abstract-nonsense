#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        vector<int> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i)
            cin>>a[i];
        int odd=0,even=0;
        for(int i=0; i<n; ++i){
            if(a[i]%2)
                odd++;
            else
                even++;
        }
        if(odd%2==0&&even%2==0){
            cout<<"YES\n";
            continue;
        }
        int done=0;
        sort(a.begin(),a.end());
        for(int i=0; i<n-1; ++i){
            if(a[i]+1==a[i+1]){
                odd--;
                even--;
            }
            if(odd%2==0&&even%2==0){
                done|=1;
            }
        }
        cout<<(done?"YES\n":"NO\n");
    }
}

// differ by 1 means parity is different
// you want to use this op to make odd%2==9 and even%2==0