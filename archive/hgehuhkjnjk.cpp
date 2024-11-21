#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a,b; cin>>a>>b;
    int left = 0, right = 1e9;
    while(left <= right){
        int mid = (left + right) / 2;
        if((mid * (mid + 1)) / 2 > a + b) right = mid - 1;
        else left = mid + 1;
    } // right is bounded by 1e5
    int mn = min(a, b);
    vector<int> p,q;
    for(int i=right;i>0;--i){
        if(mn >= i) p.push_back(i), mn -= i;
        else q.push_back(i);
    }
    if(a > b) swap(p, q);
    cout<<p.size()<<endl;
    for(int i=0;i<p.size();++i) cout<<p[i]<<' ';
    cout<<endl<<q.size()<<endl;
    for(int i=0;i<q.size();++i) cout<<q[i]<<' ';
    return 0;
}

/**
 * it's clearly better to use small numbers first
 * we take the sum of a + b and binary search for the largest note number possible
 * then it's always possible to make any number out of the sequence
 */