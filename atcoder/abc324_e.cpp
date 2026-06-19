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
    int N; string T; 
    cin>>N>>T;
    vector<string> S(N);
    for(int i=0; i<N; ++i) {
        cin>>S[i];
    }
    auto prefix=[&](const string& s)->int {
        int i=0, j=0;
        while(i<(int)s.size() && j<(int)T.size()) {
            if(s[i]==T[j]) {
                i++,j++;
            } else {
                i++;
            }
        }
        return j;
    };
    auto suffix=[&](const string& s)->int {
        int i=(int)s.size()-1, j=(int)T.size()-1;
        while(i>=0 && j>=0) {
            if(s[i]==T[j]) {
                i--,j--;
            } else {
               i--;
            }
        }
        return j;
    };
    vector<int> pf(N),sf(N);
    for(int i=0; i<N; ++i) {
        pf[i]=prefix(S[i]);
        sf[i]=suffix(S[i]);
    }
    //pf and sf represent after fitting string s, which pos is in T
    //for a prefix at j, only accept suffix at [0, j]
    //for a suffix at j, only accept prefix at [j, T.size()-1]
    vector<int> pfs(T.size()+10,0);
    for(int i=0; i<N; ++i) {
        pfs[pf[i]]++;
    }
    //build suffix sum on prefix array
    for(int i=pfs.size()-2; i>=0; --i) {
        pfs[i]+=pfs[i+1];
    }
    auto query_pfs=[&](int j)->int {
        if(j < 0) return pfs[0]; else return pfs[j];
    };
    int ans=0;
    for(int i=0; i<N; ++i) {
        ans+=query_pfs(sf[i] + 1);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
}
