// since the number can only range from [1, 999999999], thus we can brute force all the possible sums
#include <bits/stdc++.h>
using namespace std;
#define int long long

int a,b,c;
vector<int> ans;

int dsum(int n){
    int s=0;
    while(n){
        s+=(n%10);
        n/=10;
    }
    return s;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>a>>b>>c;
    for(int i=1;i<=81;++i){
        // this is a potential answer
        int x = b * (int)pow(i,a) + c;
        // check if the sum of its digits eq i 
        if(x>0 && x<1e9 && dsum(x)==i)
            ans.push_back(x);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<' ';
    return 0;
}