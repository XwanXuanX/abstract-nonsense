#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    vector<int> a(k);
    for(int i=0;i<k;++i)
        cin>>a[i];

    bool hun=false;
    vector<int> ans;
    vector<string> d;
    for(int i=0;i<k;++i){
        if(a[i] == 0){
            ans.push_back(a[i]);
        }else if(a[i] == 100){
            if(!hun)
                ans.push_back(a[i]), hun=true;
        }else{
            string nm=to_string(a[i]);
            if(nm.size() < 2)
                nm.insert(nm.begin(), '0');
            d.push_back(nm);
        }
    }

    auto cnt=[&](string& s)->int{ return s[0] + s[1] - (2 * '0'); };
    sort(d.begin(), d.end(), [&](string& p, string& q){return cnt(p) < cnt(q);});

    bool b1=false, b2=false;
    for(int i=0;i<d.size();++i){
        if(d[i][0] != '0' && d[i][1] == '0'){
            if(!b2)
                ans.push_back(stoi(d[i])), b2=true;
        }else if(d[i][0] == '0' && d[i][1] != '0'){
            if(!b1)
                ans.push_back(stoi(d[i])), b1=true;
        }else{
            if(!b1 && !b2)
                ans.push_back(stoi(d[i])), b1=true, b2=true;
        }
    }

    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<' ';
    return 0;
}