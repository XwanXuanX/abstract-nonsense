/**
 * what's the time complexity of the brute force approach
 * i think it's O(10^5 + 10^4), so not bad at all!
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

set<char> vow={'a','e','i','o','u'};

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    string a, b, c, d;
    auto findpos=[&](string& s)->int{
        int count=0;
        for(int i=s.size()-1;i>=0;--i)
            if(vow.count(s[i])){
                count++;
                if(count==k)
                    return i;
            }
        return -1;
    };
    auto rhy=[&](vector<string>& sur)->string{
        if(sur[0]==sur[1]){
            if(sur[1]==sur[2] && sur[2]==sur[3]) return "aaaa"; // all the same
            if(sur[2]==sur[3]) return "aabb"; // partionally the same
        }else{
            if(sur[0]==sur[2] && sur[1]==sur[3]) return "abab";
            if(sur[0]==sur[3] && sur[1]==sur[2]) return "abba";
        }
        return "";
    };
    set<string> ans;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c>>d;
        vector<string> in={a,b,c,d};
        vector<int> pos;
        for(int i=0;i<4;++i)
            pos.push_back(findpos(in[i]));
        for(int i=0;i<4;++i)
            if(pos[i] < 0){
                cout<<"NO"<<endl;
                return 0;
            }
        // here we need to get all the surfix
        vector<string> sur;
        for(int i=0;i<4;++i)
            sur.push_back(in[i].substr(pos[i], in[i].size()));
        // determine the rhyme based on the surfix
        string rhym=rhy(sur);
        // note that "aaaa" can rhyme with every other rhyms
        if(rhym.size()==0){ // no known rhyme scheme
            cout<<"NO"<<endl;
            return 0;
        }
        if(rhym!="aaaa") // only record non-universal pattern
            ans.insert(rhym);
        if(ans.size()>1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(ans.size()==1)
        cout<<*ans.begin()<<endl;
    else
        cout<<"aaaa"<<endl;
    return 0;
}
