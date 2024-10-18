#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    vector<pair<int,int>> events;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        events.push_back(make_pair(a, b));
    }
    // you need to sort on start and end date
    sort(events.begin(),events.end(),[](pair<int,int>& p, pair<int,int>& q){
        return p.first<q.first;});
    // we can guarentee that no two events start or end in the same day
    // when you check downwards, the starting date is already satisfied.
    // all you need to do is keep track of the maximum ending date that you've encountered
    int mx=events.front().second;
    int ans=0;
    for(int i=1;i<events.size();++i){
        if(events[i].second>mx){
            mx=events[i].second;
        }else{
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}