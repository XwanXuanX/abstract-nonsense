#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,in;
vector<int> buf;

void pfactor(int n, vector<pair<int,int>>& fas){
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            fas.push_back(make_pair(i,count));
        }
    }
    if(n>1) // n is a prime itself
        fas.push_back(make_pair(n,1));
    return;
}

bool found(int vert){
    int gap=n/vert; // the amount you increase each time
    // and you need to check from 0 -- gap-1
    for(int start=0;start<gap;++start){
        bool ok=true;
        for(int i=start;i<buf.size();i+=gap)
            if(buf[i]==0){
                ok=false;
                break;
            }
        if(ok)
            return true;
    }
    return false;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>in, buf.push_back(in);
    // prime factor n
    vector<pair<int,int>> fas;
    pfactor(n,fas);
    // generate all the possibilities to check
    vector<int> check;
    for(int i=0;i<fas.size();++i)
        if(fas[i].first==2){
            if(fas[i].second>1)
                check.push_back(4);
        }else{
            check.push_back(fas[i].first);
        }
    // now for each of the convex polygon, check
    for(int i=0;i<check.size();++i)
        if(found(check[i])){
            cout<<"YES"<<endl;
            return 0;
        }
    cout<<"NO"<<endl;
    return 0;
}

/**
 * do prime factorization it's more optimal to use prime numbers to check
 * the number of unique prime factors of a number under 1e5 cannot exceed 6 (has been proven)
 * thus you can check all possibilities, starting from every node, because you can visiting each node exactly once
 */
