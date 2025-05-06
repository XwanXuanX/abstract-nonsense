/**
 * the key is to identify the repeating sequence of 45, 36, 27, and 18
 * if the sequence if even, the only one possibilities
 * if odd, then two possibilities
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    string n;
    cin>>n;
    if(n.size()==1){ // you cannot perform any operation
        cout<<1<<endl;
        return 0;
    }
    // transform string into int
    transform(n.begin(),n.end(),n.begin(),[](char c){return c-'0';});
    // we need to find all segments which has the repeating pattern
    int start=0, next=9-n[0], ans=1;
    for(int i=1;i<n.size();++i){
        if(n[i]!=next){ // the streak is broken, current segment is [start, i-1]
            int sz=i-start;
            if(sz%2==1 && sz>=2) // there are sz ways to do it since any number can stay alone
                ans*=(sz/2+1);
            // reset start and next
            start=i;
        }
        next=9-n[i];
    }
    // take care of the last segment
    if(start<n.size()-1){
        int sz=n.size()-start;
        if(sz%2==1 && sz>=2)
            ans*=(sz/2+1);
    }
    cout<<ans<<endl;
    return 0;
}
