#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,a;
vector<int> buf;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a, buf.push_back(a);
    sort(buf.begin(), buf.end());
    set<int> ans;
    for(int i=0;i<buf.size();++i){
        if(buf[i]%k!=0){
            ans.insert(buf[i]);
        }else{
            if(!ans.count(buf[i]/k))
                ans.insert(buf[i]);
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}