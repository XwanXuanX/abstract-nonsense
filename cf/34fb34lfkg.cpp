#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m,k;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m>>k;
    // since you didn't say how long each tube should be, then I can move down the zig-zag manner
    // and the condition will be fullfilled
    int i=1, j=1, dir=0, moved=1;
    // implicitly update i and j to be the next coord in zig-zag
    auto getnext=[&]()->bool{
        if((j==m || j==1) && !moved){
            i++;
            moved=1;
            if(i>n)
                return false;
            dir=!dir;
        }else{
            if(!dir)
                j++;
            else
                j--;
            moved=0;
        }
        return true;
    };
    auto print=[&]()->bool{
        cout<<i<<' '<<j<<' ';
        return getnext();
    };
    int tot=0;
    while(k--){
        // if the tube is the last one, we print to the end
        if(k==0){
            cout<<(n*m)-tot<<' ';
            do{ cout<<i<<' '<<j<<' '; }while(getnext());
            break;
        }else{
            tot+=2;
            cout<<2<<' ';
            print();
            print();
            cout<<endl;
        }
    }
    return 0;
}