#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define int long long
#define INF (1ll<<60)

#ifndef ONLINE_JUDGE
        #include "debug.hpp"
        #define debug(...) do { __VA_ARGS__ } while (0)
#else
        #define debug(...) do {} while (0)
#endif

void solve() {
        int n,q;
        cin>>n>>q;
        set<pair<int,int>> seg;
        auto find_first=[&](int l){
                auto it=seg.lower_bound({l,LLONG_MIN});
                if(it!=seg.begin()) {
                        auto prev_it=prev(it);
                        if(prev_it->second>=l) {
                                it=prev_it;
                        }
                }
                return it;
        };
        auto find_last=[&](int r){
                return seg.upper_bound({r,LLONG_MAX});
        };
        int blk=0;
        while(q--) {
                int l,r;
                cin>>l>>r;
                //check overlap and merge
                auto front=find_first(l);
                auto last=find_last(r);
                if(front==last) {
                        //no overlap, simple case
                        seg.insert({l,r});
                        blk+=r-l+1;
                        cout<<n-blk<<'\n';
                } else {
                        //overlapping intervals are [first,last)
                        //calculate the new interval
                        int nl=min(l,front->first);
                        int nr=max(r,prev(last)->second);
                        for(auto it=front; it!=last; ++it) {
                                blk-=it->second-it->first+1;
                        }
                        seg.erase(front,last);
                        seg.insert({nl,nr});
                        blk+=nr-nl+1;
                        cout<<n-blk<<'\n';
                }
                //debug(print(seg););
        }

}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
