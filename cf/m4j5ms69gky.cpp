#include <bits/stdc++.h>
using namespace std;
#define int long long

int p2(int a){
    int cnt1=0,mx=0;
    for(int i=0; i<32; ++i){
        if(a&(1<<i)){
            cnt1++;
            mx=max(mx,i);
        }
    }
    return (cnt1>1)?-1:mx;
}

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
        // if some element is not a power of 2
        // then it can only be used when there is an exact same ele before
        vector<int> b,c;
        for(int i=0; i<n; ++i){
            int pp=p2(a[i]);
            if(pp==-1){
                b.push_back(a[i]);
            }else{
                c.push_back(a[i]-pp);
            }
        }
        int ans=0;
        map<int,int> cnt;
        for(int i=0; i<b.size(); ++i){
            ans+=cnt[b[i]];
            cnt[b[i]]++;
        }
        cnt.clear();
        for(int i=0; i<c.size(); ++i){
            ans+=cnt[c[i]];
            cnt[c[i]]++;
        }
        cout<<ans<<'\n';
    }
}