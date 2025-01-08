#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        vector<int> a;
        cin>>n;
        a.resize(2*n);
        for(int i=0; i<2*n; ++i)
            cin>>a[i];
        vector<int> odd,even;
        for(int i=0; i<2*n; ++i){
            if(a[i]%2)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        if(odd.size()%2){
            odd.pop_back();
            even.pop_back();
        }else{
            if(odd.size()>=2){
                odd.pop_back();
                odd.pop_back();
            }else{
                even.pop_back();
                even.pop_back();
            }
        }
        for(int i=0; i<(int)odd.size()-1; i+=2)
            cout<<odd[i]+1<<' '<<odd[i+1]+1<<'\n';
        for(int i=0; i<(int)even.size()-1; i+=2)
            cout<<even[i]+1<<' '<<even[i+1]+1<<'\n';
    }
}