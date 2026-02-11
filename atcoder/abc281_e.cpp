// Problem: E - Least Elements
// Contest: AtCoder - AtCoder Beginner Contest 281
// URL: https://atcoder.jp/contests/abc281/tasks/abc281_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
constexpr int INF = 1ll<<60;
constexpr int MOD = 1000000007; // 998244353;
template<typename T> using MaxPQ = priority_queue<T,vector<T>,less<T>>;
template<typename T> using MinPQ = priority_queue<T,vector<T>,greater<T>>;
template<typename T> bool chmin(T& a,const T& b) {if(b<a){a=b;return true;}return false;}
template<typename T> bool chmax(T& a,const T& b) {if(b>a){a=b;return true;}return false;}

void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    multiset<int> low,high;
    int sumlow=0;
    auto fix=[&]()->void {
        while(!low.empty() && !high.empty()) {
            auto lowMax=prev(low.end());
            auto highMin=high.begin();
            if(*lowMax<=*highMin) {
                break;
            }
            const int mx=*lowMax, mn=*highMin;
            sumlow-=mx; sumlow+=mn;
            low.erase(lowMax), high.erase(highMin);
            low.insert(mn), high.insert(mx);
        }
    };
    auto rebalance=[&]()->void {
        fix();
        while(low.size()>=k) {
            auto it=prev(low.end());
            sumlow-=*it;
            high.insert(*it);
            low.erase(it);
        }
        while (low.size()<k && !high.empty()) {
            auto it=high.begin();
            sumlow+=*it;
            low.insert(*it);
            high.erase(it);
        }
        fix();
    };
    auto add=[&](const int x)->void {
        if(k==0) {
            high.insert(x);
            return;
        }
        if(!low.empty() && x<=*prev(low.end())) {
            low.insert(x);
            sumlow+=x;
        } else {
            high.insert(x);
        }
        rebalance();
    };
    auto remove=[&](const int x)->void {
        const auto itLow=low.find(x);
        if(itLow!=low.end()) {
            sumlow -= *itLow;
            low.erase(itLow);
        } else {
            auto itHigh=high.find(x);
            high.erase(itHigh);
        }
        rebalance();
    };
    
    for(int i=0; i<m; ++i) {
        add(a[i]);
    }
    vector<int> ans={sumlow};
    for(int l=1, r=m; r<n; ++r, ++l) {
        remove(a[l-1]);
        add(a[r]);
        ans.push_back(sumlow);
    }
    for(int i=0; i<ans.size(); ++i) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; //cin>>T;
    while(T--) solve();
}