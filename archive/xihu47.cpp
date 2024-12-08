/**
 *   1 1 1 0 1 1 1 1
 * 1 0 0 -1 0 1 1 1 1
 * 1 0 0 -1 1 0 0 0 -1
 * 1 0 0 0 0 1 0 0 -1
 * 
 *   1 1 0 1 1 0 1 1 1
 * 1 0 -1 1 0 -1 1 0 0 -1
 * 1 0 0 0 1 0 0 1 0 -1
 * 
 *   1 1 0 1 1
 * 1 0 -1 1 0 -1
 * 1 0 0 -1 0 -1
 * 
 *   1 0 1 0 1 1
 *   1 0 1 1 0 -1
 *   1 1 0 -1 0 -1
 * 1 0 -1 0 -1 0 -1
 */

#include <bits/stdc++.h>
using namespace std;
#define uint unsigned int

void solve(){
    uint x; cin>>x;
    vector<int> bits;
    for(int i=0; i<31; ++i) if(x & (1<<i)) bits.push_back(1); else bits.push_back(0);
    int start=0;
    vector<pair<int,int>> segment, copy;
    for(int i=1; i<bits.size(); ++i) if(bits[i]!=bits[i-1]) segment.push_back(make_pair(start, i-1)), start=i;
    segment.push_back(make_pair(start,bits.size()-1));
    copy_if(segment.begin(), segment.end(), back_inserter(copy), [&](auto& p){return bits[p.first]==1;});
    for(auto& p:copy)
        if(bits[p.first] && p.second-p.first+1 > 1){
            bits[p.second+1] = 1;
            for(int i=p.first+1; i<=p.second; ++i) bits[i]=0;
            bits[p.first] = -1;
        }
    bits.push_back(0);
    for(int i=1; i<bits.size()-1; ++i){
        if(bits[i]==-1 && bits[i-1]==1) bits[i-1]=-1, bits[i]=0;
        else if(bits[i]==1 && bits[i-1]==1) bits[i+1]=1, bits[i]=0, bits[i-1]=-1;
    }
    cout<<bits.size()<<endl;
    for(int i=0; i<bits.size(); ++i) cout<<bits[i]<<' ';
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}