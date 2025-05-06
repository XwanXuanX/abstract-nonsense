#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    int left=1, right=n;
    auto ok=[&](int v)->bool{
        int tot=0, p=1;
        while((v/p) > 0){
            tot+=(v/p);
            p *= k;
        }
        return tot>=n;
    };
    while(left<=right){
        int mid=(left+right)/2;
        if(ok(mid))
            right=mid-1;
        else
            left=mid+1;
    }
    cout<<left<<endl;
    return 0;
}

/**
 * the upper bound of v is 1e9
 * worst case is v = 1e9 and k = 2, when will v/k^e == 0?
 * loop will execute for at most 30 times
 * 30 * log(1e9)
 */