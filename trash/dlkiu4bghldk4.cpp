/**
 * 1 2 3 4 5
 * 3 1 2 4 5
 * 1 3 2 4 5 thus we can sure that 3 and 1 must have new message update
 * claim: if we search from the back, the first increasing number is the place where new message happen
 * if the index increases, then it means all the threads in front of it must also have new messages
 * so that it pushes back the first one
 */

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
    for(int i=buf.size()-1;i>0;--i)
        if(buf[i]<buf[i-1]){
            cout<<i<<endl;
            return 0;
        }
    cout<<0<<endl;
    return 0;
}