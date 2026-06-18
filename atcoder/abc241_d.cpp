#include <bits/stdc++.h>
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
    int Q; cin>>Q;
    multiset<int> s;
    while(Q--) {
        int a,b,c; cin>>a;
        if(a==1) {
            cin>>b;
            s.insert(b);
        } else if(a==2) {
            cin>>b>>c;
            auto it = s.upper_bound(b);
            bool bad=false;
            for(int i=0; i<c; ++i) {
                if(it==s.begin()) {
                    bad=true;
                    break;
                }
                it--;
            }
            if(!bad) {
                cout<<*it<<'\n';
            } else {
                cout<<-1<<'\n';
            }
        } else {
            cin>>b>>c;
            auto it=s.lower_bound(b);
            bool bad=false;
            for(int i=0; i<c-1; ++i) {
                if(it==s.end()) {
                    bad=true;
                    break;
                }
                it++;
            }
            if(bad || it==s.end()) {
                cout<<-1<<'\n';
            } else {
                cout<<*it<<'\n';
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; //cin>>T;
    while(T--) solve();
}
