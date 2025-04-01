#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string a,b;
        cin>>n>>a>>b;
        int n0e=0, n0o=0;
        for(int i=0; i<n; i+=2)
            if (b[i] == '0')
                n0e++;
        for(int i=1; i<n; i+=2)
            if (b[i] == '0')
                n0o++;
        int n1e=0, n1o=0;
        for(int i=0; i<n; i++) {
            if (i%2==0) {
                if (a[i] == '1')
                    n1e++;
            } else {
                if (a[i] == '1')
                    n1o++;
            }
        }
        if (n0o >= n1e && n0e >= n1o){
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}

// 000001
// 111011