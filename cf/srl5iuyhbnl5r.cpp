#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b;
    cin>>n;
    map<int,int> cnt;
    vector<pair<int,int>> cards(n);
    for(int i=0;i<n;++i){
        cin>>a>>b;
        cnt[a]++;
        if(a != b) cnt[b]++; // even if a card has same color on the front and back, can only display one
        cards[i] = make_pair(a, b);
    }

    // check if it's possible to obtain an answer
    int half = (n%2) ? (n/2)+1 : n/2;
    bool ok=false;
    vector<int> pos;
    for(auto& p:cnt)
        if(p.second >= half) ok=true, pos.push_back(p.first);
    if(!ok){
        cout<<-1<<endl;
        return 0;
    }

    // for the given color, return the number of operations needed to be done
    auto check=[&](int color)->int{
        int tot=0;
        for(int i=0;i<cards.size();++i)
            if(cards[i].first == color) tot++;
        if(tot >= half)
            return 0;
        return half - tot;
    };

    // check the possible answers manually, maximum 4 iterations
    int ans=LLONG_MAX;
    for(int i=0;i<pos.size();++i)
        ans=min(ans, check(pos[i]));

    cout<<ans<<endl;
    return 0;
}

/**
 * what is the upper bound of the checking?
 * there can be at most 4 colors, then we can brute force them
 */