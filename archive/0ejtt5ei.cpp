#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum(int n) {
    return (n * (n+1)) / 2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,x,y;
        cin>>n>>x>>y;
        int com = lcm(x, y);
        int plus = sum(n) - sum(n - n/x + n/com);
        int minus = sum(n/y - n/com);
        cout<<plus-minus<<'\n';
    }
}