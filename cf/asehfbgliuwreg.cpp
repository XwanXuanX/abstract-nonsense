#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    string me,in,n;
    getline(cin,me);
    getline(cin,n);
    map<string,int> factor;

    // if the action is associated with me, then return the name
    // otherwise, return the empty string
    auto parse=[&](string action)->string{
        string X, Y;
        for(int i=0;i<action.size();++i){
            if(action[i]==' ') break;
            X.push_back(action[i]);
        }
        // find the only '\''
        int found=action.find('\'');
        assert(found!=string::npos);
        // construct the other name
        for(int i=found-1;i>=0;--i){
            if(action[i]==' ') break;
            Y.push_back(action[i]);
        }
        reverse(Y.begin(), Y.end());
        // check if the action is associated with me
        if(X==me) return Y;
        if(Y==me) return X;
        // if the action is not associated with me, then we need to add the name anyways
        factor[X]; factor[Y];
        return "";
    };

    while(getline(cin, in)){
        string name=parse(in);
        if(name.size())
            factor[name]++;
    }

    vector<pair<string,int>> ans;
    for(auto& p:factor)
        ans.push_back(p);
    sort(ans.begin(), ans.end(),
    [](pair<string,int>& p, pair<string,int>& q)->bool{
        if(p.second!=q.second)
            return p.second>q.second;
        return p.first<q.first;
    });

    for(int i=0;i<ans.size();++i)
        cout<<ans[i].first<<endl;

    return 0;
}
