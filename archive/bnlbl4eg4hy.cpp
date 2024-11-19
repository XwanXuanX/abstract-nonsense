#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
 * THIS SOLUTION WORKS BUT TLE
 */

// return a list of prime numbers that divides n
set<int> factor(int n){
    set<int> A;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            A.insert(i);
        }
    }
    if(n>1) A.insert(n);
    return A;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    set<int> prime;
    for(int i=0;i<a.size();++i){
        set<int> A = factor(a[i]);
        for(auto d:A){
            if(prime.count(d)){
                cout<<"YES"<<endl;
                return;
            }else{
                prime.insert(d);
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}

/**
 * we need to get the divisors of each number
 * don't actually need to get all the divisors, getting all the prime divisors is enough
 * using prime factorization
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}