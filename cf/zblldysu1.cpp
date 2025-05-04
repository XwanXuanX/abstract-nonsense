#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string s,fst;
        cin>>n>>s;
        fst.resize(n,'0');
        for(int i=0; i<n; ++i){
            if(s[i]!='9'){
                fst[i]='0'+('9'-s[i]);
            }
        }
        if(fst[0]>'0'){
            cout<<fst<<'\n';
            continue;
        }
        // need to add 111...11112
        string rest,ans;
        rest.resize(n,'1');
        rest[n-1]++;
        ans.resize(n);
        int carry=0;
        for(int i=n-1; i>=0; --i){
            int left=fst[i]-'0', right=rest[i]-'0';
            int sum=left+right+carry;
            ans[i]=(char)((sum%10)+'0');
            carry=sum/10;
        }
        cout<<ans<<'\n';
    }
}

// if n does not start with 9, then the fstwer is obvious
// if n start with 9, we can only make the result start with 1 at most