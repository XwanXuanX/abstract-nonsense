#include <bits/stdc++.h>
using namespace std;

int a,b,l,r;

bool overlap(int x_start, int x_end, int y_start, int y_end){
    return x_start <= y_end && y_start <= x_end;
}

bool complete_overlap(int x_start, int x_end, int y_start, int y_end){
    return ((x_start<=y_start && x_end>=y_end) || (y_start<=x_start && y_end>=x_end));
}

void solve(){
    cin>>a>>b>>l>>r;
    if(!overlap(a,b,l,r)){
        cout<<1<<endl;
        return;
    }
    if(complete_overlap(a,b,l,r)){
        int res=0;
        if(max(b,r) > min(b,r)) res++;
        if(min(a,l) < max(a,l)) res++;
        cout<<res+min(b-a, r-l)<<endl;
        return;
    }
    // 1 2 3 4
    cout<<2+(min(b,r)-max(a,l))<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}