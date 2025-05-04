#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, d; cin >> n >> m >> d;
    vector<int> ans(n);
    set<int> a;
    map<int,int> idx;
    for(int i = 0; i < n; ++i){
        int in; cin >> in;
        idx[in] = i;
        a.insert(in);
    }

    int day = 1;
    while(a.size()){
        vector<int> hold;
        int start = *a.begin();
        hold.push_back(start);
        ans[idx[start]] = day;
        auto it = a.upper_bound(start + d);
        while(it != a.end()){
            start = *it;
            hold.push_back(start);
            ans[idx[start]] = day;
            it = a.upper_bound(start + d);
        }
        for(int i = 0; i < hold.size(); ++i)
            a.erase(hold[i]);
        day++;
    }

    cout << *max_element(ans.begin(), ans.end()) << endl;
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}

/**
 * partition a so that every element in each partition is at least d apart
 * if 1 does not select imm next, then it must select some bigger number, then the imm next must be dealt by the number after 1
 * this is suboptimal
 */