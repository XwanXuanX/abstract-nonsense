#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        int start=0;
        vector<pair<int,int>> seg;
        for(int i=1; i<s.size(); ++i){
            if(s[i]!=s[i-1]){
                seg.push_back(make_pair(start,i-1));
                start=i;
            }
        }
        seg.push_back(make_pair(start,s.size()-1));
        if(seg.size()==1){
            cout<<1<<' '<<s.size()<<' '<<1<<' '<<1<<'\n';
            continue;
        }
        int l1=seg[0].second-seg[0].first+1;
        int l2=seg[1].second-seg[1].first+1;
        if(l2>=l1){
            cout<<1<<' '<<s.size()<<' '<<1<<' '<<s.size()-l1<<'\n';
        }else{
            int start=seg[1].first+1-l2;
            int end=start+(s.size()-seg[1].first)-1;
            cout<<1<<' '<<s.size()<<' '<<start<<' '<<end<<'\n';
        }
    }
}