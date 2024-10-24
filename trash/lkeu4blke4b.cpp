#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

constexpr int N=1e5+10;
int buf[N];

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,h,in,sum=0;
    cin>>n>>m>>h;
    for(int i=1;i<=m;++i){
        cin>>in;
        buf[i]=in;
        sum+=in;
    }
    if(sum<n){
        cout<<-1<<endl;
        return 0;
    }
    int rest=sum-buf[h];
    if(n-1>rest){
        cout<<1<<endl;
        return 0;
    }
    if(buf[h]<2){
        cout<<0<<endl;
        return 0;
    }
    double ans=1.0;
    double x=sum-buf[h], y=sum-1;
    for(int i=1;i<=n-1;++i){
        ans*=(x/y);
        x--, y--;
    }
    cout<<1.0-ans<<endl;
    return 0;
}