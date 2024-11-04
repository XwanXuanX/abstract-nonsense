#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,k;
    string s,t;
    cin>>n>>k>>s>>t;

    map<char,int> cnt;
    for(int i=0;i<n;++i){
        if(i>=k || i+k<n){ // you can move around in each sector, and you can move between sectors
            cnt[s[i]]++;
            cnt[t[i]]--;
        }else{
            if(s[i]!=t[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    for(auto& p:cnt)
        if(p.second!=0){
            cout<<"NO"<<endl;
            return;
        }
    
    cout<<"YES"<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}

/**
 * it can be seen that given infinite length, you can swap any two characters and make s and t equal
 * the constraint is sometimes you cannot move further to one direction
 */