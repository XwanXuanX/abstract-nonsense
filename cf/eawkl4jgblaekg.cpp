#include <bits/stdc++.h>
using namespace std;
#define int long long 

/**
 * what matters is the number of 1s each player can get
 * the relative amount of 1 is the same
 */
 
signed main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        string s,t;
        cin>>n>>s>>t;
        // count how many 1s are in both strs
        int cs=0, ts=0;
        for(int i=0;i<s.size();++i)
                if(s[i]=='1')
                        cs++;
        for(int i=0;i<t.size();++i)
                if(t[i]=='1')
                        ts++;
        // count the overlapping 1s
        int count=0;
        for(int i=0;i<s.size();++i)
                if(s[i]=='1' && s[i]==t[i])
                        count++;
                        
        int ls=cs-count, lt=ts-count;
        bool turn = (count%2 == 0); // if even, the next turn will be First
        int scoreF=(count%2 == 1) ? 1 : 0, scoreT=0;
        while(ls > 0 || lt > 0){
                if(turn){ // First
                        if(ls > 0) ls--, scoreF++;
                        else lt--;
                        turn=false;
                }else{ // Second
                        if(lt > 0) lt--, scoreT++;
                        else ls--;
                        turn=true;
                }
        }
        
        if(scoreF > scoreT)
                cout<<"First"<<endl;
        else if(scoreF == scoreT)
                cout<<"Draw"<<endl;
        else
                cout<<"Second"<<endl;
        
        return 0;
}