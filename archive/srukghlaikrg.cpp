#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,in;
    cin>>n;
    vector<int> a,b;
    for(int i=0;i<n;++i)
        cin>>in, a.push_back(in);
    for(int i=0;i<n;++i)
        cin>>in, b.push_back(in);
    // now we need to arrange them one by one. it can be proven that the total number of swaps needed is bounded by O(n^2)
    vector<pair<int,int>> ans;
    // swap a student with specific height to this target.
    auto swapppp=[&](int target){
        int height=a[target];
        // b is sorted before target, so don't need to search that part
        int match=target;
        for(match=target;match<b.size();++match)
            if(b[match]==height) // in this case we found a match
                break;
        if(match==target)
            return; // we don't need to swap at all
        // otherwise we need to swap all the way from match to target
        while(match>target){
            swap(b[match],b[match-1]);
            ans.push_back(make_pair(match, match+1));
            match--;
        }
    };
    for(int i=0;i<a.size();++i){
        swapppp(i);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    return 0;
}

/**
 * 3 2 1 2
 * 3 1 2 2
 * 1 2 3 2
 * 1 3 2 2
 * 1 2 3 2
 */