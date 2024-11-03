#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(n==2){ // you cannot do anything
        if(s[0]!='0')
            cout<<s<<endl;
        else
            cout<<s[1]<<endl;
        return;
    }

    if(n==3){ // you can enumerate all cases
        int ans=LLONG_MAX;
        for(int i=1;i<=2;++i){
            int f = stoi(s.substr(0,i)), se = stoi(s.substr(i,s.size()));
            ans=min(ans, min(f * se, f + se));
        }
        cout<<ans<<endl;
        return;
    }

    // if there exists at least one 0, you can make all the results 0
    for(int i=0;i<s.size();++i)
        if(s[i]=='0'){
            cout<<0<<endl;
            return;
        }

    // otherwise, sum up the remaining digits
    int sum=0;
    for(int i=0;i<s.size();++i)
        if(s[i]!='1')
            sum+=(s[i]-'0');
    
    int ans=LLONG_MAX;
    for(int i=0;i<s.size()-1;++i){
        int f = s[i]-'0', se = s[i+1]-'0';
        if(f == 1){
            if(se == 1) ans=min(ans, sum + 11);
            else ans=min(ans, sum + 10);
        }else{
            if(se == 1) ans=min(ans, sum - f + ((f * 10) + 1));
            else ans=min(ans, sum - f + (f * 10));
        }
    }

    cout<<ans<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

/**
 * if 1, better to multiply
 * if 0, make all multiply
 * if number bigger than 1, better to add
 * 
 * n-2 means two digits must be grouped together
 * 
 * 19811678487321784121 = 
 * 9 8 6 7 8 4 8 7 3 2 7 8 4 12
 */