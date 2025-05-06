#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    string s;
    cin>>s;
    vector<int> bs;
    for(int i=0;i<s.size();++i)
        if(s[i]=='B')
            bs.push_back(i);
    
    if(bs.size()==0){
        cout<<0<<endl;
        return;
    }

    vector<int> left(bs.size(),0), right(bs.size(),0);
    auto getleft=[&](int i)->int{ // if you go left, how much can you gain?
        if(bs[i] == 0)
            return 0;
        if(i == 0)
            return bs[i];
        return bs[i] - bs[i-1] - 1;
    };
    auto getright=[&](int i)->int{ // if you go right, how much can you gain?
        if(bs[i] == s.size()-1)
            return 0;
        if(i == bs.size()-1)
            return s.size() - bs[i] - 1;
        return bs[i+1] - bs[i] - 1;
    };

    left[0] = getleft(0);
    right[0] = getright(0);

    for(int i=1;i<bs.size();++i){
        left[i] = getleft(i) + left[i-1];
        right[i] = getright(i) + max(left[i-1], right[i-1]);
    }

    cout<<max(left[bs.size()-1], right[bs.size()-1])<<endl;
    return;
}

/**
 * for each B in s, we'll see which direction is most optimal to move
 * for each B we have a choice, go left or go right, so it's a dp problem!
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}