#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int x;
        cin >> x;
        // all numbers less than 5 are not ok
        if (x <= 4) {
            cout<<-1<<'\n';
            continue;
        }
        vector<int> bits;
        while(x) {
            bits.push_back(x & 1);
            x >>= 1;
        }
        // reverse(bits.begin(), bits.end());
        // if is a power of 2, then not ok
        int n1 = accumulate(bits.begin(), bits.end(), 0);
        if (n1 == 1 || n1 == bits.size()) {
            cout<<-1<<'\n';
            continue;
        }
        // otherwise, we can always find an answer
        vector<int> ans;
        for(int i=0; i<bits.size(); ++i) {
            ans.push_back(!bits[i]);
        }
        for (int i=0; i<bits.size(); ++i) {
            if(bits[i]){
                ans[i] = 1;
                break;
            }
        }
        int ans_ = 0;
        for (int i=0; i<ans.size(); ++i) {
            ans_ |= (ans[i] << i);
        }
        cout<<ans_<<'\n';
    }
}

/**
 * The comment is really interesting lol (it's curly!)
 * if x is a power of 2, then not possible; if x=3, then also not possible
 * 110
 * 011
 * 101
 */