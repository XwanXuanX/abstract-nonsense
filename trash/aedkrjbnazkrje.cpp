/**
 * so if a and b have the same value at the same location, that is considered one
 * 1 2 2
 * 2 2 2
 * 1 2 2 2 2 2
 * you cannot reorder the outer, but you can reorder the inner part
 * 5! ways to order 5 distinct 2s, but only 3 distinct 2s here, so ...
 * 5! / (2! x 2!)
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
vector<int> a, b, c;
constexpr int NN = 1e5 + 10;
int factor[NN];

// calculate the factorials with mod m
void prep(){
    factor[0]=1;
    for(int i=1;i<=NN;++i)
        factor[i] = ((factor[i-1] % m) * (i % m)) % m;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    a.resize(n), b.resize(n);
    for(int i=0;i<n;++i)
        cin>>a[i], c.push_back(a[i]);
    for(int i=0;i<n;++i)
        cin>>b[i], c.push_back(b[i]);
    cin>>m;
    prep();

    // find the number of unique pairs for each number
    map<int,int> unq;
    for(int i=0;i<a.size();++i)
        if(a[i]==b[i])
            unq[a[i]]++;

    // find the outer order, which cannot be changed
    sort(c.begin(),c.end());
    // partition
    vector<pair<int,int>> segment;
    int start=0;
    for(int i=1;i<c.size();++i)
        if(c[i]!=c[i-1])
            segment.push_back(make_pair(start, i-1)), start=i;
    segment.push_back(make_pair(start,c.size()-1));

    int ans=1;
    for(int i=0;i<segment.size();++i){
        int sz=segment[i].second-segment[i].first+1;
        // here we need to take care of the same pair problem
        int same=unq[c[segment[i].first]];
        ans = ((ans * factor[sz]) / (2 * same)) % m;
        // ans = ((((ans % m) * (factor[sz] % m)) % m) / (((2 % m) * (same % m)) % m)) % m;
    }

    cout<<ans<<endl;
    return 0;
}