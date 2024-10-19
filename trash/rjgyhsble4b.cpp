/**
 * if n is even, must divide equally, if odd, floordiv by 2 + 1
 * difference can be no more than max(a)
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,in;
    cin>>n;
    vector<pair<int,int>> boy;
    for(int i=0;i<n;++i){
        cin>>in;
        boy.push_back(make_pair(in,i+1));
    }
    sort(boy.begin(),boy.end());
    int x=0, y=0; // cumulative score for each team
    int left=0, right=boy.size()-1;
    vector<int> X,Y;
    using pr=pair<int,int>;
    auto select=[&](pr& p, pr& q)->pair<pr,pr>{
        if(p.first<q.first) return make_pair(p,q);
        return make_pair(q,p);
    };
    while(left<right){
        auto[mn,mx]=select(boy[left], boy[right]);
        if(x<y){
            // assign the stronger one to the weak team
            X.push_back(mx.second), x+=mx.first;
            Y.push_back(mn.second), y+=mn.first;
        }else{
            // in case of a tie, assign randomly
            X.push_back(mn.second), x+=mn.first;
            Y.push_back(mx.second), y+=mx.first;
        }
        left++, right--;
    }
    // in case of n is odd, assign the last one to the weaker team
    if(left==right){
        if(x<y) X.push_back(boy[left].second);
        else Y.push_back(boy[left].second);
    }
    // format the output
    cout<<X.size()<<endl;
    for(auto i:X) cout<<i<<' ';
    cout<<endl<<Y.size()<<endl;
    for(auto i:Y) cout<<i<<' ';
    return 0;
}
