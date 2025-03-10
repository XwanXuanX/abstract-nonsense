#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int l,r;
        cin>>l>>r;

        if (r != l) {
            int even = (r % 2 == 0) ? r : r - 1;
            int ans = even / 2;
            if (ans == 1) {
                cout<<-1<<'\n';
            } else  {
                cout<<ans<<' '<<ans<<'\n';
            }
            continue;
        }

        vector<int> factor;
        for(int i=2; i*i<=l; ++i) {
            if(l%i == 0 ) {
                while(l%i == 0) {
                    l /= i;
                }
                factor.push_back(i);
            }
        }
        if(l > 1){
            factor.push_back(l);
        }
        if(factor.empty() || factor[0] == r){
            cout<<-1<<'\n';
        } else {
            int p = factor.front();
            cout<<p<<' '<<r-p<<'\n';
        }
    }
}