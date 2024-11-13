#include <bits/stdc++.h>
using namespace std;
#define int long long

int dsum(int n){
    int s=0;
    while(n)
        s+=n%10, n/=10;
    return s;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    set<int> active;
    for(int i=0;i<a.size();++i)
        if(a[i]>9) // it can be further reduced
            active.insert(i);

    // query time
    int t,l,r,x;
    for(int i=0;i<q;++i){
        cin>>t;
        if(t==1){
            cin>>l>>r; l--, r--;
            int lst=l;
            while(active.size()){
                auto it=lower_bound(active.begin(), active.end(), lst);
                if(it == active.end() || *it > r){ // if we go to far, then we stop
                    break;
                }
                // reduce the element
                a[*it] = dsum(a[*it]);
                int tmp=*it;
                active.erase(it);
                if(a[tmp] > 9) // can be further reduced
                    active.insert(tmp);
                lst=tmp+1;
            }
        }else{
            cin>>x; x--;
            cout<<a[x]<<endl;
        }
    }

    return;
}

/**
 * each point can only be reduced by 2 times, at most
 * if we can track the number of reduce of each number, we can output in constant time
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}