/**
 * 2 2 3
 * 1 2 3
 * 1. 3 1
 * 2. 3 2
 * 3. 3 1
 * 4. 2 1
 * 
 * note that it's always more optimal to arrange people who want to play more first
 * 2 2 3 = 2 2 3
 * 3 2 3 = 2 1 2
 * 3 3 3 = 1 1 1
 * 2 2 3 4 = 2 2 3 4
 * 3 2 3 4 = 2 1 2 3
 * 3 3 3 4 = 1 1 1 2
 * 4 3 3 4 = 1 0 0 1
 * 4 4 3 4 = 0 0 -1 0
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,in;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    int sum=accumulate(a.begin(),a.end(),0ll);
    cout<<max(((int)ceil((double)sum / (n-1))), *max_element(a.begin(),a.end()))<<endl;
    return 0;
}