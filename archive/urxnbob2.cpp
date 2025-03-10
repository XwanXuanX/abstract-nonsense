#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            cin>>a[i];
        }

        if(n == k) {
            vector<int> t;
            for(int i=1; i<n; i+=2) {
                t.push_back(a[i]);
            }
            t.push_back(0);
            for(int i=0; i<t.size(); ++i) {
                if(t[i] != (i+1)) {
                    cout<<i+1<<'\n';
                    break;
                }
            }
            continue;
        }

        int not_one = 0;
        for(int i=1; i<n-k+2; ++i) {
            if(a[i] != 1){
                not_one |= 1;
            }
        }
        if(not_one){
            cout<<"1\n";
        }else {
            cout<<"2\n";
        }
    }
}