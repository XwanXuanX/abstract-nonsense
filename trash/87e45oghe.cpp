#include <bits/stdc++.h>
using namespace std;
#define int long long

int days[]={0,
31,
28,
31,
30,
31,
30,
31,
31,
30,
31,
30,
31
};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    // basic sliding window problem: there can be no more than 10^5 such dates
    map<string,int> cnt;
    auto check=[&](int left, int right){ // check if the giving string is a date, if yes, then store it
        bool valid=true;
        for(int i=left;i<=right;++i)
            if(i-left!=2 && i-left!=5)
                valid &= isdigit(s[i]);
        valid &= (s[left+2] == '-' && s[left+5] == '-');
        if(!valid)
            return;
        cnt[s.substr(left,right-left+1)]++;
    };
    for(int left=0, right=9; right<s.size(); ++right, ++left)
        check(left, right);
    // print()
    auto valid=[&](const string& date)->bool{ // check if the date is valid
        string d=date.substr(0,2), m=date.substr(3,2), y=date.substr(6,4);
        int day=stoi(d), month=stoi(m), year=stoi(y);
        // check year and month
        if(year<2013 || year>2015 || month<1 || month>12)
            return false;
        // check date
        if(day<1 || day>days[month])
            return false;
        return true;
    };
    string ans;
    int mx=-1;
    for(auto& p:cnt)
        if(p.second > mx && valid(p.first)){
            mx=p.second;
            ans=p.first;
        }
    cout<<ans<<endl;
}