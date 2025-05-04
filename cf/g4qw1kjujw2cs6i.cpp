#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> a;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    vector<vector<string>> b(6);
    for(int i=0; i<n; ++i)
        b[a[i].size()].push_back(a[i]);
    vector<map<int,int>> cnt(6);
    for(int i=1; i<=5; ++i){
        for(int j=0; j<b[i].size(); ++j){
            int tot=accumulate(b[i][j].begin(),b[i][j].end(),0);
            cnt[i][tot]++;
        }
    }
    int ans=0;
    for(int k=1; k<=5; ++k){
        for(int j=1; j<=k; ++j){
            if((k+j)%2!=0){
                continue;
            }
            // crop this amount from the begin and end of each string
            // k is the longer string, j is the shorter string
            int hf=(k+j)/2;
            for(int i=0; i<b[k].size(); ++i){
                string& bt=b[k][i];
                int tot=accumulate(bt.begin(),bt.end(),0);
                // left
                int left=0;
                for(int m=0; m<hf; m++)
                    left+=bt[m];
                // right
                int right=0;
                for(int m=k-1; m>=k-hf; --m)
                    right+=bt[m];
                ans+=cnt[j][2*left-tot];
                if(k>j)
                    ans+=cnt[j][2*right-tot];
            }
        }
    }
    cout<<ans<<'\n';
}