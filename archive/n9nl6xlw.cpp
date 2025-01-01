#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        vector<int> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i)
            cin>>a[i];
        vector<pair<int,int>> seg;
        int st=0;
        for(int i=1; i<n; ++i){
            if(((a[i]%2)+(a[i-1]%2))%2==0){
                seg.push_back(make_pair(st,i-1));
                st=i;
            }
        }
        seg.push_back(make_pair(st,n-1));
        int ans=INT_MIN;
        for(int i=0; i<seg.size(); ++i){
            int mx=INT_MIN;
            int tot=0;
            for(int j=seg[i].first; j<=seg[i].second; ++j){
                tot=max(0,tot+a[j]);
                mx=max(mx,tot);
            }
            if(mx<=0){
                mx=INT_MIN;
                for(int j=seg[i].first; j<=seg[i].second; ++j)
                    mx=max(mx,a[j]);
            }
            ans=max(ans,mx);
        }
        cout<<ans<<'\n';
    }
}