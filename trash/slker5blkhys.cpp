#include <bits/stdc++.h>
using namespace std;
#define int long long

int len(int n){
    int res=0;
    while(n) res++, n/=10;
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int l,r,k;
    cin>>l>>r>>k;
    // int lk = len(k);

    // find the first in range
    int pow=1;
    while(pow < l){
        if(len(pow) > 18){
            cout<<-1<<endl;
            return 0;   
        } // there is no use to continue multiplying
        pow *= k;
    }

    if(pow > r){
        cout<<-1<<endl;
        return 0;
    }

    while(pow <= r && pow >= l){
        cout<<pow<<' ';
        if(len(pow) > 18) // no need to multiple as well
            break;
        pow *= k;
    }

    return 0;
}

/**
 * 237171123124584251
 * 239852470977948384
 */