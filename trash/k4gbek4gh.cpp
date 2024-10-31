#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,in;
    cin>>n>>x;
    vector<int> buf;
    bool has=false;
    for(int i=0;i<n;++i){
        cin>>in, buf.push_back(in);
        if(in==x)
            has=true;
    }
    int ans=0;
    if(!has)
        ans++, buf.push_back(x);
    sort(buf.begin(),buf.end());
    // we are sure that there will be at least 1 x in arr
    // lb always return the first occurance
    int first=lower_bound(buf.begin(),buf.end(),x)-buf.begin();
    int last=upper_bound(buf.begin(),buf.end(),x)-buf.begin()-1;
    auto calc=[&](int front,int back)->int{ return (back>front)? abs(front-back)-1 : abs(front-back); };
    int mn=LLONG_MAX;
    for(int i=first;i<=last;++i){
        int front=i, back=buf.size()-front-1;
        if(front==back || front+1==back){
            cout<<ans<<endl;
            return 0;
        }
        mn=min(mn,calc(front,back));
    }
    cout<<mn+ans<<endl;
    return 0;
}

/**
 * if x is present in arr, then taking the first one is optimal
 * if not, we need to insert x and do the rest
 * 
 * front=3
 * back=1
 * 1 2 3 4 5
 */