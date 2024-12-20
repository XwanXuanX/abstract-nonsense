#include <bits/stdc++.h>
using namespace std;
#define yetong_li_ ios_base::sync_with_stdio(0); cin.tie(0);

int n;
string s;
vector<int> cnt;

void solve(){
    cin>>n>>s;
    cnt.assign(26,0);
    for(int i=0; i<n; ++i)
        cnt[s[i]-'a']++;
    // you want to make the string alternating
    string ans;
    int pt=0;
    while(ans.size() < n){
        if(cnt[pt]>0){
            ans.push_back((char)(pt+'a'));
            cnt[pt]--;
        }
        pt = (pt+1) % 26;
    }
    cout<<ans<<'\n';
}

signed main(){
    yetong_li_
    int t; cin>>t;
    while(t--) solve();
}