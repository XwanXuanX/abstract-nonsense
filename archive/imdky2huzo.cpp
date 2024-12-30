#include <bits/stdc++.h>
using namespace std;

string ans="CCC";
vector<string> a;

vector<int> dx={1,1,1,-1,-1,-1,0,0};
vector<int> dy={1,0,-1,1,0,-1,1,-1};

void dfs(int i,int j,string& s,set<pair<int,int>>& v){
    v.insert(make_pair(i,j));
    s.push_back(a[i][j]);
    if(s.size()==3){
        ans=min(ans,s);
        v.erase(make_pair(i,j));
        s.pop_back();
        return;
    }
    for(int k=0; k<8; ++k){
        int ni=i+dx[k],nj=j+dy[k];
        if(ni<0||ni>=3||nj<0||nj>=3||v.count(make_pair(ni,nj)))
            continue;
        dfs(ni,nj,s,v);
    }
    v.erase(make_pair(i,j));
    s.pop_back();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a.resize(3);
    for(int i=0; i<3; ++i)
        cin>>a[i];
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j){
            set<pair<int,int>> v;
            string s;
            dfs(i,j,s,v);
        }
    cout<<ans<<'\n';
}