#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    string in;
    vector<string> buf;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>in, buf.push_back(in);
    vector<vector<int>> dp(n,vector<int>(m,LLONG_MAX));
    for(int i=0;i<n;++i){
        string& s=buf[i];
        int pos=s.find('1');
        if(pos==string::npos){
            cout<<-1<<endl;
            return 0;
        }
        // iter from the left
        int dist=0;
        for(int j=0;j<m;++j){
            if(s[(j+pos)%m]=='1')
                dist=0;
            else
                dist++;
            dp[i][(j+pos)%m]=min(dp[i][(j+pos)%m], dist);
        }
        // iter from the right
        dist=0;
        for(int j=m;j>0;--j){
            if(s[(j+pos)%m]=='1')
                dist=0;
            else
                dist++;
            dp[i][(j+pos)%m]=min(dp[i][(j+pos)%m], dist);
        }
    }

    // calc the answer
    int ans=LLONG_MAX;
    for(int i=0;i<m;++i){
        int tot=0;
        for(int j=0;j<n;++j)
            tot+=dp[j][i];
        ans=min(ans,tot);
    }

    cout<<ans<<endl;
    return 0;
}