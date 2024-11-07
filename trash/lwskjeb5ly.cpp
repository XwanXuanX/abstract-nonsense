#include <bits/stdc++.h>
using namespace std;
#define int long long 

/**
 * THIS IS A BAD ATTEMPT
 */

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    // int base=0, ans=0;
    // while(base < n-1){
    //     int mn=LLONG_MAX;
    //     for(int i=base+1;i<n;++i){
    //         if(a[i] < a[base]){
    //             base = i;
    //             break;
    //         }
    //         if(a[i] < mn){
    //             ans++;
    //             mn=a[i];
    //         }
    //         if(i == n-1){
    //             base = i;
    //             break;
    //         }
    //     }
    // }

    int ans=0, start=0;
    for(start=1;start<n;++start)
        if(a[start] > a[start-1])
            break;
    
    if(start==n){
        cout<<0<<endl;
        return;
    }

    int base=start-1, mn=LLONG_MAX;
    for(int i=start;i<n;++i){
        if(a[i] < mn && a[i] > a[base]){
            ans++;
            mn = a[i];
        }
    }

    cout<<ans<<endl;
    return;
}

/**
 * the lucky number is any number that only has exactly one distance away from 1
 * so such number must appear to the right of 1, and also cannot have element smaller than it
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}