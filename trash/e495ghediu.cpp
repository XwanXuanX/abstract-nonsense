// there are 4 * 1e4 permutations, which we can brute force
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;
string in;
vector<string> ss,sss;
vector<int> perm;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>in, ss.push_back(in), sss.push_back(in);
    for(int i=0;i<k;++i)
        perm.push_back(i);
    // compute the minimum difference from all integers
    auto comp=[&]()->int{
        int mn=LLONG_MAX, mx=LLONG_MIN;
        for(int i=0;i<sss.size();++i){
            int n=stoi(sss[i]);
            mn=min(mn,n), mx=max(mx,n);
        }
        return mx-mn;
    };
    // reorder ss by the given sequence
    auto reo=[&](){
        for(int i=0;i<ss.size();++i){
            for(int j=0;j<perm.size();++j)
                sss[i][perm[j]]=ss[i][j];
        }
    };
    int ans=LLONG_MAX;
    do{
        reo();
        ans=min(ans,comp());
    }while(next_permutation(perm.begin(),perm.end()));

    cout<<ans<<endl;
    return 0;
}