#include <bits/stdc++.h>
using namespace std;
#define int long long

set<char> open = {'<','[','{','('};
map<char,char> mp = {
    {')','('},
    {']','['},
    {'}','{'},
    {'>','<'}
};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;

    int ans=0;
    deque<char> stk;
    if(open.count(s.front())){
        stk.push_back(s.front());
    }else{
        cout<<"Impossible"<<endl;
        return 0;
    }

    for(int i=1;i<s.size();++i){
        if(!open.count(s[i])){ // it's a closing brace, check match
            if(stk.size()==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
            if(stk.back() != mp[s[i]])
                ans++;
            stk.pop_back();
        }else{ // it's a open brace, push it in
            stk.push_back(s[i]);
        }
    }

    if(stk.size())
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;

    return 0;
}