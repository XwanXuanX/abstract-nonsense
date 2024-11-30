#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s1, s2; cin >> s1 >> s2;
    map<char,char> mp;
    for(int i = 0; i < s1.size(); ++i){
        if(!mp.count(s1[i]) && !mp.count(s2[i])) mp[s1[i]] = s2[i], mp[s2[i]] = s1[i];
        else if(mp.count(s1[i]) && mp[s1[i]] != s2[i] || mp.count(s2[i]) && mp[s2[i]] != s1[i])
        { cout << -1 << endl; return 0; }
    }
    vector<pair<char,char>> ans;
    for(char i = 0; i < 26; ++i)
        if(mp.count('a' + i) && mp['a' + i] != 'a' + i){
            ans.push_back(make_pair('a' + i, mp['a' + i]));
            mp.erase(mp['a' + i]);
        }
    cout << ans.size() << endl;
    for(auto& p : ans) cout << p.first << ' ' << p.second << endl;
    return 0;
}
