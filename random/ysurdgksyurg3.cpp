#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    string in;
    set<string> all;
    for(int _=0;_<n;++_){
        cin>>in;
        // generate all substrings of string in
        for(int i=0;i<in.size();++i){
            string sub;
            sub.push_back(in[i]);
            all.insert(sub);
            for(int j=i+1;j<in.size();++j){
                sub.push_back(in[j]);
                all.insert(sub);
            }
        }
    }

    // we need to find the lexicographically minimum, but also the shortest!
    vector<string> All(all.begin(),all.end());
    sort(All.begin(),All.end(),[](string& p,string& q){
        if(p.size()!=q.size())
            return p.size()<q.size();
        return p<q;
    });

    vector<pair<int,int>> segments;
    int start=0;
    for(int i=1;i<All.size();++i){
        if(All[i-1].size()!=All[i].size()){
            segments.push_back(make_pair(start,i-1));
            start=i;
        }
    }
    segments.push_back(make_pair(start,All.size()-1));

    // construct the next lex successor string
    auto cons=[&](string& str)->string{
        for(int i=str.size()-1;i>=0;--i){
            if(str[i]!='z'){
                str[i]++;
                return str;
            }
            str[i]='a';
        }
        // assume that this will not reach the limit
        return "";
    };

    // now for each partition, we check from aa.....a
    for(auto[start,end]:segments){
        // the start string must contains all a
        string& first=All[start];
        if(any_of(first.begin(),first.end(),[](char c){return c!='a';})){
            for(int i=0;i<first.size();++i)
                cout<<'a';
            cout<<endl;
            return 0;
        }
        for(int i=start;i<end;++i){
            string next=cons(All[i]);
            if(next!=All[i+1]){
                cout<<next<<endl;
                return 0;
            }
        }
        // we've reach the end: this means all the strings before are consecutive
        string next=cons(All[end]);
        if(next.size()!=0){
            cout<<next<<endl;
            return 0;
        }
    }

    return 0;
}