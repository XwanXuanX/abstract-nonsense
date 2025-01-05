#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        priority_queue<int,vector<int>,less<int>> pq;
        int p;
        for(int i=0; i<3; ++i){
            cin>>p;
            if(p>0)
                pq.push(p);
        }
        int ans=0;
        while(pq.size()>1){
            int p=pq.top();
            pq.pop();
            int q=pq.top();
            pq.pop();
            p--;
            q--;
            if(p)
                pq.push(p);
            if(q)
                pq.push(q);
            ans++;
        }
        if(pq.size()==0){
            cout<<ans<<'\n';
            continue;
        }
        if(pq.top()%2!=0){
            cout<<-1<<'\n';
        }else{
            cout<<ans<<'\n';
        }
    }
}