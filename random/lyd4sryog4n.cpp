// AAAAAABBBB
// BAAAAAABBB
// AAAABABAAB
// BAAAAABAAB
// BAABB
// BBAAB
#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string s;
        cin>>n>>s;
        int posA=-1;
        vector<int> pos;
        for(int i=0; i<n; ++i){
            if(s[i]=='A'){
                if(posA==-1){
                    posA=i;
                }
            }else{
                if(posA!=-1){
                    pos.push_back(i);
                }
            }
        }
        pos.insert(pos.begin(),posA);
        int ans=0;
        for(int i=1; i<pos.size(); ++i){
            ans+=(pos[i]-pos[i-1]);
        }
        cout<<ans<<'\n';
    }
}