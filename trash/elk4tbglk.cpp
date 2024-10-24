#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int feet=n/36, rem=n%36;
    int inch=rem/3, rm=rem%3;
    if(rm>=2)
        inch++;
    feet+=(inch/12);
    inch%=12;
    cout<<feet<<' '<<inch<<endl;
    return 0;
}