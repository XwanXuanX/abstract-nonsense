#include <bits/stdc++.h>
using namespace std;

string s;

void solve(){
    cin>>s;
    int cnt2=0, cnt3=0, tot=0;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='2')
            cnt2++;
        else if(s[i]=='3')
            cnt3++;
        
        tot += (s[i] - '0');
    }

    for(int i=0; i<=min(2,cnt3); ++i)
        for(int j=0; j<=min(8,cnt2); ++j)
            if(((tot + (i*6 + j*2)) % 9) == 0){
                cout<<"YES\n";
                return;
            }
        
    cout<<"NO\n";
}

// the goal is to make the sum of all digits div by 9
// using 3->9 and 2->4
// that is tot + (n*6 + m*2) must be div by 9
// what matters is only 0-8 2s, and 0-2 3s.

signed main(){
    int t; cin>>t;
    while(t--) solve();
}