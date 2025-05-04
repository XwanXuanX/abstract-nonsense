#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<vector<int>> a(n);
        for(int i=0; i<n; ++i){
            int k;
            cin>>k;
            a[i].resize(k);
            for(int j=0; j<k; ++j){
                cin>>a[i][j];
            }
        }
        map<int,int> cnt;
        for(int i=0; i<n; ++i){
            for(int j=0; j<a[i].size(); ++j){
                cnt[a[i][j]]++;
            }
        }
        int done=0;
        for(int i=0; i<n; ++i){
            int good=1;
            for(int j=0; j<a[i].size(); ++j){
                good&=(cnt[a[i][j]]>=2);
            }
            if(good){
                done|=1;
                break;
            }
        }
        if(done){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}

// for f(q)==f(p), then the set of set bits in p should be a subset
// of that in q (or vice versa)
// so include as many sets as possible (since higher chance of being the superset)