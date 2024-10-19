/**
 * for n
 * get all the divisors of n, so we know (A-1)(B-2)(C-2) must be in the divisor list
 * then fix A and B, get C, calculate the answer
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 

void gen(vector<pair<int,int>>& A, int i, int d, set<int>& divs){
    if(i==A.size()){
        divs.insert(d);
        return;
    }
    for(int p=0;p<=A[i].second;++p){
        gen(A,i+1,d,divs);
        d*=A[i].first;
    }
}

void fdiv(int n, set<int>& divs){
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
    gen(A,0,1,divs);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    set<int> divs;
    fdiv(n, divs);
    vector<int> Ds(divs.begin(), divs.end());
    // since the number of divisors of 10e9 is small, thus we can tolorate O(n^2) operation
    int mn=LLONG_MAX, mx=LLONG_MIN;
    for(int i=0;i<Ds.size();++i){
        for(int j=0;j<Ds.size();++j){
            int A=Ds[i], B=Ds[j];
            if(A*B > n || n%(A*B) != 0)
                continue;
            int C=n/(A*B);
            int ans=((A+1)*(B+2)*(C+2))-n;
            mn=min(mn,ans), mx=max(mx,ans);
        }
    }
    cout<<mn<<' '<<mx<<endl;
    return 0;
}