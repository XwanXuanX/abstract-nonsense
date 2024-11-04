#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x,p;
    cin>>n>>x>>p;
    for(int i=1;i<=min(2*n,p);++i)
        if((x + (i*(i+1))/2) % n == 0){
            cout<<"Yes"<<endl;
            return;
        }
    cout<<"No"<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

/**
 * x -> 0 you need (n-x) + k * n, where k is any non-negative integer
 * f = 3, then 1:3 2:2 3:1 4:0 so for a force f, the wheel will only move f * (f+1) / 2 sectors
 * we can definitely brute force it if p is small
 * for any arithmetic sequence, you can always get any number in that sequence
 */