// if contains both even and odd, then 2
// 4 6 8 678954
// if the values are sorted, then k cannot be as large as the 3rd biggest value
// if all even, then 4
// 1 3 5 77 89
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        int even=0, odd=0;
        for(int i=0; i<n; ++i){
            even|=(!(a[i]%2));
            odd|=(a[i]%2);
        }
        if(even&&odd){
            cout<<2<<'\n';
            continue;
        }
        sort(a.begin(),a.end());
        vector<int> d;
        for(int i=1; i<n; ++i){
            d.push_back(a[i]-a[i-1]);
        }
        int gd=d[0];
        for(int i=1; i<d.size(); ++i){
            gd=gcd(gd,d[i]);
        }
        cout<<2*gd<<'\n';
    }
}

// if each element increase as a multiple of k, then ai mod k will all be the same
// d1 d2 d3 d4 ... all must be a multiple of 2