#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; scanf("%d %d", &n,&k);
    if(n==1){
        printf("%d\n", k);
        return;
    }
    int msb=0;
    for(int i=0; i<32; ++i) if((1<<i) & k)
        msb=max(msb, i);
    printf("%d %d ", (1<<msb)-1, k-(1<<msb)+1);
    for(int i=2; i<n; ++i) printf("0 ");
    printf("\n");
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; scanf("%d", &t);
    while(t--) solve();
}