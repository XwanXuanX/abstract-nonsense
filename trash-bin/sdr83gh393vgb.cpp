#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,in;
    cin>>n;
    vector<int> buf;
    for(int i=0;i<n;++i){
        cin>>in;
        buf.push_back(in);
    }
    int ans=LLONG_MIN;
    int start=0, end=0;
    // since the constraints are small, we can brute force all pairs
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(buf[i]!=buf[j])
                continue;
            // compute the answer if we fix the start and ending point
            int sum=2*buf[i];
            for(int k=i+1;k<j;++k){
                if(buf[k]>0)
                    sum+=buf[k];
            }
            if(sum>ans){
                ans=sum;
                start=i;
                end=j;
            }
        }
    }

    // count the trees need to be cut down
    vector<int> cut;
    for(int i=0;i<n;++i){
        if(i<start) cut.push_back(i);
        else if(i>end) cut.push_back(i);
        else if((i>start && i<end) && buf[i]<0) cut.push_back(i);
    }
    cout<<ans<<' '<<cut.size()<<endl;
    for(auto i:cut)
        cout<<i+1<<' ';
    cout<<endl;
    return 0;
}
