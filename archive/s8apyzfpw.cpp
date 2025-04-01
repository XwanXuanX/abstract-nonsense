#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m,k;
        cin>>n>>m>>k;
        // the maximum item to be distributed on one row
        int perrow = (int)ceil((double)k / n);
        // then we binary search the answer
        int left=1, right=perrow, ans=LLONG_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;
            // check if it's ok
            int need = perrow + (mid - 1);
            if (need <= m) {
                left = mid + 1;
                int mxLen = (int)ceil((double)perrow / mid);
                ans = min(ans, mxLen);
            } else {
                right = mid - 1;
            }
        }
        cout<<ans<<'\n';
    }
}

/**
 * distribute evenly across all rows
 * if a row must contain some items, if you can break up into m segments, with n items each segment,
 * then need (m-1) + (m*n) slots
 * 10 / 3 = 3...1 = 4 and 3
 * xxxx xxxx xx
 * xxx xxx xxx x
 * xx xx xx xx xx
 */