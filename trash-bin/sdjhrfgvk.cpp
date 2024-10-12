#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    string S;
    int N;
    cin>>S>>N;
    // the only non-possible is when S contains more unique character than N
    map<char,int> cnt;
    for(char c:S)
        cnt[c]++;
    if(cnt.size()>N){
        cout<<-1<<endl;
        return 0;
    }
    // otherwise it's always possible
    // the sheet must contains all unique characters
    map<char,int> ans;
    int mxneed=0, tot=cnt.size();
    for(auto& p:cnt){ // initialize the answer
        ans[p.first]=1;
        mxneed=max(mxneed,p.second);
    }

    auto ceil=[&](int num, int d)->int{return (num%d==0)? num/d : (num/d) + 1;};
    while(tot<=N && mxneed>1){
        // check which character is most needed
        int need=0;
        char ch;
        for(auto& p:cnt){
            int nd=ceil(p.second, ans[p.first]);
            if(nd>need){
                need=nd;
                ch=p.first;
            }
        }
        mxneed=need;
        if(tot==N)
            break;
        // append that character to answer
        ans[ch]++;
        tot++;
    }

    // construct the answer
    string out;
    for(auto& p:ans){
        for(int i=0;i<p.second;++i)
            out.push_back(p.first);
    }
    // in case of the need character is not long enough, append redundancy
    for(int i=out.size();i<N;++i)
        out.push_back('a');
    cout<<mxneed<<endl;
    cout<<out<<endl;
    return 0;
}

/**
 * banana
 * b:1
 * n:4
 * a:3
 * 
 * start with basic bna, who cause the most buy will increase it's count
 * time complexity:
 * O(1000 * 26)
 * DORIHG;OASDRGH;GGGGFFFFF
 */