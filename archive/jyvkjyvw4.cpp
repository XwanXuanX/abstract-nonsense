#include <bits/stdc++.h>
using namespace std;
#define int long long

int checkset(int n){
    for(int i = 0; i < 64; ++i) if((1ll << i) & n) return i;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, a, b; cin >> n >> q;
    vector<int> cnt(64, 0);
    for(int i = 0; i < n; ++i){
        cin >> a;
        cnt[checkset(a)]++;
    }
    while(q--){
        cin >> b;
        vector<int> qcnt(cnt.begin(), cnt.end());
        vector<bool> bits(64, false);
        for(int i = 0; i < 64; ++i) if((1ll << i) & b) bits[i] = true;
        for(int i = 0; i < 64; ++i){
            if(bits[i]){
                if(qcnt[i] == 0){
                    cout << -1 << endl;
                    break;
                }
                qcnt[i]--;
            }
            if(i < 63)
                qcnt[i + 1] += (qcnt[i] / 2);
        }
    }
}