#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];

    sort(a.begin(),a.end());
    // then we need to prepare the prefix sum to query range sum
    vector<int> pfs(a.begin(), a.end());
    for(int i=1;i<pfs.size();++i)
        pfs[i] += pfs[i-1];
    auto sum=[&](int l, int r)->int{
        if(l == 0)
            return pfs[r];
        return pfs[r] - pfs[l-1];
    };

    auto ok=[&](int mid, int right, int target)->bool{
        int sm = sum(mid, right);
        int len = right-mid+1;
        return ((target * len) - sm) <= k;
    };

    // given the search bound, return the length of the segment
    auto search=[&](int r, int target)->int{
        int left=0, right=r;
        while(left<=right){
            int mid=(left+right)/2;
            if(ok(mid, r, target))
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    };

    int ans=LLONG_MIN, num=0;
    for(int i=0;i<a.size();++i){
        int len=i-search(i,a[i])+1;
        if(len > ans){
            ans=len;
            num=a[i];
        }
    }
    
    cout<<ans<<' '<<num<<endl;
    return 0;
}

/**
 * 6 3 4 0 2
 * 0 2 3 4 6 k=3
 * first we need to sort the numbers
 * how to efficiently find the bound binary search according to cumulative sum
 */