#include <bits/stdc++.h>
using namespace std;
#define int long long 

string a,b;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>a>>b;
    if(a.size()!=b.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    // otherwise, if there is at least one 1 in a and at least one 1 in b, they can be made equal
    bool ah=false, bh=false;
    for(int i=0;i<a.size();++i)
        if(a[i]=='1'){
            ah=true;
            break;
        }
    for(int i=0;i<b.size();++i)
        if(b[i]=='1'){
            bh=true;
            break;
        }
    if((ah && bh) || (!ah && !bh))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}