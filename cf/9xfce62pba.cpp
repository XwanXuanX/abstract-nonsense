#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i].first>>a[i].second;
        }
        set<int> _fixed;
        map<int,int> cnt;
        for(int i=0; i<n; ++i){
            if(a[i].first==a[i].second){
                _fixed.insert(a[i].first);
                cnt[a[i].first]++;
            }
        }
        vector<int> fixed(_fixed.begin(),_fixed.end()); // sorted
        string ans;
        for(int i=0; i<n; ++i){
            int l=a[i].first, r=a[i].second;
            if(r>l){ // check if the range is filled up
                auto i1=lower_bound(fixed.begin(),fixed.end(),l);
                auto i2=lower_bound(fixed.begin(),fixed.end(),r);
                if(i1==fixed.end() || i2==fixed.end() || *i1!=l || *i2!=r){
                    ans.push_back('1');
                }else{
                    ans.push_back((i2-i1+1==r-l+1) ? '0' : '1');
                }
            }else{ // check if it's the only one
                ans.push_back((cnt[l]==1) ? '1' : '0');
            }
        }
        cout<<ans<<'\n';
    }
}