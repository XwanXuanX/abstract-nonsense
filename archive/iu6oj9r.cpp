#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<int> ans;
        ans.push_back(a[0]);
        int left=1, right=n-1, isLeft=0;
        while(left<=right){
            if(!isLeft){
                ans.push_back(a[right]);
                right--;
                isLeft=1;
            }else{
                ans.push_back(a[left]);
                left++;
                isLeft=0;
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0; i<n; ++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
}