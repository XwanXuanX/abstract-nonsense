#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<string> mat(n);
        for(int i=0; i<n; ++i) {
            cin>>mat[i];
        }
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        for(int i=0; i<n; ++i) {
            bool full = true;
            for(int j=0; j<m; ++j) {
                if (mat[i][j] != '1'){
                    full = false;
                }
                if (full) {
                    cnt[i][j]++;
                }
            }
        }
        for (int j=0; j<m; ++j) {
            bool full = true;
            for (int i=0; i<n; ++i) {
                if (mat[i][j] != '1'){
                    full = false;
                }
                if (full) {
                    cnt[i][j]++;
                }
            }
        }

        // compute the ans
        bool ok = true;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if (mat[i][j] == '1' && cnt[i][j] == 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}

/**
 * clearly, each 1 should at least have 1 attached sides
 * from left or from top. we can keep a count of the number of sides each 1
 * is attached to.
 */