#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int rest,int n,int l,int t,int P){
    // if you are going to study for n-rest days
    // then it's more optimal to use the last few days to do the task
    int study=n-rest;
    int ntask=(int)ceil((double)n/7);
    int p=(study*l)+(min(ntask,2*study)*t);
    return p>=P;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,P,l,t;
        cin>>n>>P>>l>>t;
        int ll=0,rr=n;
        while(ll<=rr){
            int mid=(ll+rr)/2;
            if(ok(mid,n,l,t,P)){
                ll=mid+1;
            }else{
                rr=mid-1;
            }
        }
        cout<<ll-1<<'\n';
    }
}