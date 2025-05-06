#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(string& s){
    vector<pair<int,int>> segment;
    int start = 0;
    for(int i=1;i<s.size();++i) if(s[i] == s[i-1]) segment.push_back(make_pair(start, i-1)), start = i;
    segment.push_back(make_pair(start, s.size()-1));
    int res = 0;
    for(auto& p:segment) res = max(res, p.second - p.first + 1);
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    if(s.front() == s.back()){ cout<<calc(s)<<endl; return 0; }
    int left = 0;
    for(; left < s.size() - 1; left++) if(s[left] == s[left + 1]) break;
    if(left == s.size() - 1){ cout<<s.size()<<endl; return 0; }
    // otherwise we can perform split and reverse once takes constant time
    string front = s.substr(0, left+1), last = s.substr(left+1, s.size());
    reverse(front.begin(), front.end()); reverse(last.begin(), last.end());
    string res = front + last;
    cout<<calc(res)<<endl;
}