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
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        int good=1;
        map<int,int> cnt;
        for(int i=0; i<n; ++i){
            cnt[a[i]]++;
            good&=(a[i]>=1&&a[i]<=n);
            good&=(cnt[a[i]]<=2);
        }
        if(!good){
            cout<<"NO\n";
            continue;
        }
        set<int> vis;
        set<int> ps,qs;
        vector<int> p(n,0),q(n,0);
        for(int i=1; i<=n; ++i){
            ps.insert(i);
            qs.insert(i);
        }
        for(int i=0; i<n; ++i){
            if(!vis.count(a[i])){
                vis.insert(a[i]);
                p[i]=a[i];
                ps.erase(a[i]);
            }else{
                q[i]=a[i];
                qs.erase(a[i]);
            }
        }
        // greedly find the largest masking element
        for(int i=0; i<n; ++i){
            if(p[i]!=0){
                auto it=qs.upper_bound(p[i]);
                if(it==qs.begin()){
                    good&=0;
                    break;
                }
                --it;
                q[i]=*it;
                qs.erase(it);
            }else{
                auto it=ps.upper_bound(q[i]);
                if(it==ps.begin()){
                    good&=0;
                    break;
                }
                --it;
                p[i]=*it;
                ps.erase(it);
            }
        }
        if(!good){
            cout<<"NO\n";
            continue;
        }
        assert(ps.size()==0&&qs.size()==0);
        cout<<"YES\n";
        for(int i=0; i<n; ++i){
            cout<<p[i]<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; ++i){
            cout<<q[i]<<' ';
        }
        cout<<'\n';
    }
}

// some obs:
// 1. for all 1<=a_i<=n
// 2. each element appear at most twice

// if a is a permutation, then just print a twice
// 5 3 2 3 5
// 5 3 2
//       3 5