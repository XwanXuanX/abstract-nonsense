#include <bits/stdc++.h>
using namespace std;
#define int long long

int cur = 1;

int step(int cur, int x){
    if(cur - x > 0) return cur - x;
    return cur + x;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, s; cin >> n >> k >> s;
    if(k * (n - 1) < s || k > s){ cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    while(k > 0){
        int l = min(n - 1, s - (k - 1));
        cur = step(cur, l);
        cout << cur << ' ';
        s -= l, k -= 1;
    }
}