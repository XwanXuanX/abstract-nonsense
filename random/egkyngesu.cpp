#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int n18,n21,n25;
    n18=n21=n25=n;
    n18 -= n21/2;
    int ans = n21/2;
    n21 = n21%2;
    if(n21){
        ans++;
        n18 = max(n18-2, 0);
    }
    ans += n18/3;
    n18 = n18%3;
    if(n18 == 2)
        ans++;
    else if(n18 == 1)
        ans++, n25--;
    ans += n25/2;
    n25 = n25%2;
    if(n25)
        ans++;
    cout<<ans<<endl;
}