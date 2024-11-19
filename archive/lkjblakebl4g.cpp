#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;
    cin>>n>>x;

    if(n==x){
        cout<<n<<endl;
        return;
    }

    vector<bool> dn, dx;
    for(int i=0;i<62;++i){
        dn.push_back((1ll << i) & n);
        dx.push_back((1ll << i) & x);
    }

    // x cannot have 1 that n does not have
    for(int i=0;i<dn.size();++i)
        if(!dn[i] && dx[i]){
            cout<<-1<<endl;
            return;
        }
    
    // x can only have fewer bits than n
    // needs to be turn off by adding more numbers
    int diff=0;
    for(diff=dn.size()-1; diff>=0; diff--)
        if(dn[diff] != dx[diff])
            break;
    
    dn[diff+1] = true;
    for(int i=0;i<=diff;++i)
        dn[i] = false; // this will make the bits after diff also 0, so we need to check that as well

    for(int i=diff; i>=0; --i)
        if(dx[i]){
            cout<<-1<<endl;
            return;
        }

    // construct the number
    int ans=0;
    for(int i=0;i<dn.size();++i)
        if(dn[i])
            ans |= (1ll << i);

    if(ans < n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return;
}

/**
 * 011
 * 010
 */

/**
 * firstly, x cannot be greater than n, otherwise the answer always exists
 * secondly, we need to analyze bitwise
 * 20 = 10100
 * 21 = 10101
 * 22 = 10110
 * 23 = 10111
 * 24 = 11000
 * 16 = 10000
 * 
 * 10 = 001010
 * 42 = 100000 // this is not possible
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}