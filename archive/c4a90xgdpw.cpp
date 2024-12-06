#include <bits/stdc++.h>
using namespace std;

const int N=26;
const int INF=1e9;
string s,t;
vector<int> S(N,INF), T(N,INF);

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s>>t;

    if(t.size() < 2 || s.size() < 2){
        cout<<-1<<endl;
        return 0;
    }

    for(int i=1; i<s.size(); ++i)
        S[s[i]-'a'] = min(S[s[i]-'a'], i);

    int bestlen=INF;
    int besti=-1;
    for(int i=t.size()-2; i>=0; --i){
        if(S[t[i]-'a'] != INF){
            int tot = S[t[i]-'a'] + t.size() - i;
            if(tot < bestlen){
                bestlen = tot;
                besti = i;
            }
        }
    }

    if(besti == -1){
        cout<<-1<<endl;
        return 0;
    }

    string ans;
    for(int i=0; i<S[t[besti]-'a']; ++i)
        ans.push_back(s[i]);
    for(int i=besti; i<t.size(); ++i)
        ans.push_back(t[i]);

    cout<<ans<<endl;
    return 0;
}