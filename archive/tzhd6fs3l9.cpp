#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0; i<s.size(); ++i){
        if(s[i]=='r')
            cout<<i+1<<'\n';
        else
            st.push(i+1);
    }
    while(st.size()){
        cout<<st.top()<<'\n';
        st.pop();
    }
}