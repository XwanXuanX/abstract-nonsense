#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m,t,a,b;
vector<int> buf;
constexpr int MOD = 1000000000;
constexpr int NN = 110;
int Fc[NN];

void prep(){
        Fc[0] = Fc[1] = 1;
        for(int i=2;i<NN;++i)
                Fc[i] = (Fc[i-1] + Fc[i-2]) % MOD;
}

signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>n>>m;
        prep();
        buf.resize(n);
        for(int i=0;i<n;++i)
                cin>>buf[i];
        
        // assume left and right are 0-base indexing
        auto calc=[&](int left, int right)->int{
                int res=0;
                for(int i=left;i<=right;++i)
                        res = (res + (((Fc[i-left] % MOD) * (buf[i] % MOD)) % MOD)) % MOD;
                return res;
        };
        
        for(int i=0;i<m;++i){
                cin>>t>>a>>b;
                if(t==1)
                        buf[a-1]=b;
                else
                        cout<<calc(a-1, b-1)<<endl;
        }
        
        return 0;
}