#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;

    int mx = n * (n/2);
    if(n%2)
        mx += (n/2) + 1;
    
    if(k > mx){
        cout<<"NO"<<endl;
        return 0;
    }

    vector<string> mat;
    for(int i=0;i<n;++i){
        string row;
        for(int j=0;j<n;++j)
            row.push_back('S');
        mat.push_back(row);
    }

    bool done=false;
    // print the checkerboard pattern
    for(int i=0;i<n;++i){
        for(int j = (i%2) ? 1 : 0; j<n;j+=2){
            if(k==0){
                done=true;
                break;
            }
            mat[i][j] = 'L', k--;
        }
        if(done)
            break;
    }

    cout<<"YES"<<endl;
    for(int i=0;i<mat.size();++i)
        cout<<mat[i]<<endl;
    
    return 0;
}