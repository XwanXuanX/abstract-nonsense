#include <bits/stdc++.h>
using namespace std;
#define int long long 

string a,b;

bool ok(int ai, int bi, int ai1, int bi1){
    // if all zero, can transform
    if(ai==0 && ai1==0 && bi1==0 && bi==0) return true;
    // if a one exists in a and b, can transform
    if((ai==1 || ai1==1) && (bi==1 || bi1==1)) return true;
    return false;
}

bool turn(int i){
    // we check both sides i+1, and i-1
    int ai=a[i], bi=b[i];
    if(i>0){ // i with i-1
        int ai1=a[i-1], bi1=b[i-1];
        if(ok(ai,bi,ai1,bi1)){
            // cout<<ai1<<ai<<' '<<bi1<<bi<<endl;
            return true;
        }
    }
    if(i<a.size()-1){ // i with i+1
        int ai1=a[i+1], bi1=b[i+1];
        if(ok(ai,bi,ai1,bi1)){
            // cout<<ai<<ai1<<' '<<bi<<bi1<<endl;
            return true;
        }
    }
    return false;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>a>>b;
    auto conv=[](char c){return c-'0';};
    transform(a.begin(),a.end(),a.begin(),conv);
    transform(b.begin(),b.end(),b.begin(),conv);
    if(a.size()!=b.size()){
        cout<<"NO"<<endl;
        return 0;
    }
    // for any characters that mismatch, we need to check if we can turn it into b
    for(int i=0;i<a.size();++i){
        if(a[i]==b[i])
            continue;
        if(!turn(i)){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    // all the mismatch can be resolved
    cout<<"YES"<<endl;
    return 0;
}