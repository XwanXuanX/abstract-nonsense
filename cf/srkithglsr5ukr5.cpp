#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    string s,p;
    cin>>s>>p;
    // not possible to form any substrings!
    if(p.size()>s.size()){
        cout<<0<<endl;
        return 0;
    }
    vector<int> pcnt(26,0), scnt(26,0);
    for(int i=0;i<p.size();++i)
        pcnt[p[i]-'a']++;
    int ans=0, quest=0;
    for(int i=0;i<p.size();++i){
        if(s[i]=='?')
            quest++;
        else
            scnt[s[i]-'a']++;
    }
    // check if the current substring is good
    auto good=[&]()->bool{
        for(int i=0;i<26;++i){
            if(scnt[i]>pcnt[i])
                return false;
        }
        return (accumulate(scnt.begin(),scnt.end(),0ll) + quest == p.size());
    };
    if(good())
        ans++;
    for(int left=0, right=p.size(); right<s.size(); ++right, ++left){
        // modify scnt
        if(s[right]=='?') quest++;
        else scnt[s[right]-'a']++;
        if(s[left]=='?') quest--;
        else scnt[s[left]-'a']--;
        if(good()) ans++;
    }
    cout<<ans<<endl;
    return 0;
}