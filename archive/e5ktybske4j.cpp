/**
 * each player will try to make the number as prime as possible
 * do prime factorization first
 * if a number contains at least 3 primes factors, 1 can win
 * if # prime >= 3, 1 win
 * if # prime == 2, 2 win
 * if # prime == 1, print 0
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int,int>> factor(int n){
    vector<pair<int,int>> A;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            A.push_back(make_pair(i,count));
        }
    }
    if(n>1)
        A.push_back(make_pair(n,1));
    return A;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<endl<<0<<endl;
        return 0;
    }
    auto pfactor=factor(n);
    int tot=0;
    for(auto& p:pfactor)
        tot+=p.second;
    if(tot==1){
        cout<<1<<endl<<0<<endl;
        return 0;
    }else if(tot==2){
        cout<<2<<endl;
        return 0;
    }
    // 1 can guarentee to win
    int ans=0;
    if(pfactor.size()>1) ans=pfactor[0].first * pfactor[1].first;
    else ans=pfactor[0].first * pfactor[0].first;
    cout<<1<<endl<<ans<<endl;
    return 0;
}