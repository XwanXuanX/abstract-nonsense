#include <bits/stdc++.h>
using namespace std;
#define int long long 

pair<int,int> fib(int n){
    if(n==0)
        return make_pair(0,1);
    auto p=fib(n >> 1);
    int c=p.first * (2 * p.second - p.first);
    int d=p.first * p.first + p.second * p.second;
    if(n&1)
        return make_pair(d, c + d);
    return make_pair(c,d);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x,y,m;
    cin>>x>>y>>m;

    if(x>=m || y>=m){ // if already m-perfect
        cout<<0<<endl;
        return 0;
    }

    // if both are negative, or one negative one zero, or both zero
    if(x<=0 && y<=0){
        cout<<-1<<endl;
        return 0;
    }

    int a=min(x,y), b=max(x,y);
    // we need some special treatment about negative numbers
    int neg=0;
    if(a<0){
        neg=(a<0) ? (int)ceil(((double)abs(a)) / b) : 0;
        a = (neg * b) - abs(a);
    }

    if(a+b >= m){
        cout<<neg+1<<endl;
        return 0;
    }

    // given the number of operations, check if can make m-perfect
    auto ok=[&](int op)->bool{
        auto p=fib(op-1);
        int sum=(p.second * a) + ((p.second + p.first) * b);
        return sum >= m;
    };

    // otherwise, there must exists the answer
    // and we binary search on the number of operations needed
    int left=2, right=90;
    while(left<=right){
        int mid=(left+right)/2;
        if(ok(mid))
            right=mid-1;
        else
            left=mid+1;
    }

    cout<<left+neg<<endl;
    return 0;
}