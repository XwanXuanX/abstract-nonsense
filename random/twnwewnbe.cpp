#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

// evaluate the function y value at x
int eval(int k, int b, int x){ return k * x + b; }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x1,x2;
    cin>>n>>x1>>x2;
    vector<pair<int,int>> lines;
    for(int i=0;i<n;++i){
        int k,b;
        cin>>k>>b, lines.push_back(make_pair(k,b));
    }

    vector<pair<int,int>> rngs;
    for(int i=0;i<lines.size();++i){
        int y1=eval(lines[i].first, lines[i].second, x1), y2=eval(lines[i].first, lines[i].second, x2);
        rngs.push_back(make_pair(y1, y2));
    }

    sort(rngs.begin(), rngs.end());

    for(int i=1;i<rngs.size();++i)
        if(rngs[i].second < rngs[i-1].second){
            cout<<"YES"<<endl;
            return 0;
        }

    cout<<"NO"<<endl;
    return 0;
}