/**
 * all the numbers will be summed up eventually
 * find the top n-1 maximum numbers
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,in;
    cin>>n;
    // // find the power of 4 of the input size
    // int tot=0, mx_store=n/4;
    // priority_queue<int,vector<int>,greater<int>> pq; // this is a min heap
    // for(int i=0;i<n;++i){
    //     cin>>in;
    //     tot+=in;
    //     pq.push(in);
    //     if(pq.size()>mx_store)
    //         pq.pop();
    // }
    // vector<int> rem;
    // while(pq.size())
    //     rem.push_back(pq.top()), pq.pop();
    // int factor=1;
    // for(int bnd=rem.size();bnd>=1;bnd/=4){
    //     for(int i=rem.size()-1;i>=(int)rem.size()-bnd;--i){
    //         tot+=(factor*rem[i]);
    //     }
    //     factor++;
    // }
    // cout<<tot<<endl;
    vector<int> buf;
    for(int i=0;i<n;++i){
        cin>>in;
        buf.push_back(in);
    }
    sort(buf.begin(),buf.end(),greater<int>());
    int ans=0;
    for(int bnd=buf.size();bnd>=1;bnd/=4){
        for(int i=0;i<bnd;++i)
            ans+=buf[i];
    }
    cout<<ans<<endl;
    return 0;
}
