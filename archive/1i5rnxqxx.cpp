#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b; scanf("%d %d %d", &n,&a,&b);
    string s;
    for(int i=0; i<a; ++i)
        s.push_back((char)min(i+'a',b+'a'-1));
    for(int i=s.size(), left=0; i<n; ++i, ++left)
        s.push_back(s[left]);
    printf("%s\n", s.c_str());
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; scanf("%d", &t);
    while(t--) solve();
}