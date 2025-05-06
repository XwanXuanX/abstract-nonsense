#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> cnt(26,0);
    for(int i=0; i<n; ++i) cnt[s[i]-'a']++;
    int besti=0,  best=0;
    int worsti=-1, worst=INT_MAX;
    for(int i=0; i<26; ++i) if(cnt[i] > best) best = cnt[i], besti = i;
    for(int i=0; i<26; ++i) if(cnt[i] > 0 && cnt[i] < worst && i != besti) worsti = i, worst = cnt[i];
    if(worsti == -1){cout<<s<<endl; return;}
    for(int i=0; i<n; ++i)
        if(s[i] == worsti+'a'){
            s[i] = (char)(besti+'a');
            break;
        }
    cout<<s<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}