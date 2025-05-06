#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scanf("%lld",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    
    map<int,int> cnt;
    for(int i=0;i<a.size();++i)
        cnt[a[i]]++;

    int flag=0, mx=LLONG_MIN;
    for(auto& p:cnt)
        if(p.second > mx){
            mx=p.second;
            flag=p.first;
        }
    
    if(mx < 2){
        printf("%d\n", -1);
        return 0;
    }
    
    // now we construct the answer
    vector<pair<int,int>> ans;
    int start=0;
    int occ = (a[0] == flag) ? 1 : 0;
    for(int i=1;i<a.size();++i){
        if(a[i]==flag)
            occ++;
        if(occ==2){
            ans.push_back(make_pair(start+1, i+1));
            occ=0;
            start=i+1;
        }
    }

    // for both even and odd, we need to cover the entire range
    ans.back().second = a.size();
    printf("%lld\n", mx / 2);
    for(auto& p:ans)
        printf("%lld %lld\n", p.first, p.second);
    return 0;
}

/**
 * count the occurance of each number
 * if a number occurs n > 1times, then there is a way to make such partition, more precisely
 * floor(n/2)
 */