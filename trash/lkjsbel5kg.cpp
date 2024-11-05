#include <bits/stdc++.h>
using namespace std;
#define int long long 

constexpr int fact5 = 120;

// calculate nC5
int comb(int n){
    int top=1;
    for(int i=0;i<5;++i)
        top *= (n-i);
    return top / fact5;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    int ways = comb(n);
    // for each of the combination, choose the rows
    int perm=1;
    for(int i=0;i<5;++i)
        perm *= (n-i);
    
    cout<<ways * perm<<endl;
    return 0;
}

/**
 * a permutation problem
 * and a combination problem
 */