/**
 * if the number must be divisible by 2 and 5, then must end in a 0
 * if the number must be divisible by 3, then the sum of all the digits must divisible by 3
 * take the summation of all the digits % 3, the remainder is what you need to remove
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n147[]={1,4,7};
int n258[]={2,5,8};

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,in;
    cin>>n;
    bool has_zero=false;
    int sum=0;
    vector<int> cnt(10,0);
    for(int i=0;i<n;++i){
        cin>>in;
        if(in==0)
            has_zero=true;
        cnt[in]++;
        sum+=in;
    }
    // if no zero, no way
    if(!has_zero){
        cout<<-1<<endl;
        return 0;
    }
    int rem=sum%3;
    auto print=[&](){ // print the answer based on the cnt array
        int tot=0; // count the total number of non-zero digits
        for(int i=9;i>=1;--i){
            tot+=cnt[i];
            for(int j=0;j<cnt[i];++j)
                cout<<i;
        }
        if(tot==0){ // if no non-zero digits
            cout<<0<<endl;
            return;
        }
        for(int i=0;i<cnt[0];++i) // put the zeros at the end
            cout<<0;
        cout<<endl;
    };
    if(rem==0){ // it's trivially true
        print();
        return 0;
    }
    // otherwise, we need to remove some numbers
    if(rem==1){
        for(int i=0;i<3;++i)
            if(cnt[n147[i]] > 0){
                sum-=n147[i], cnt[n147[i]]--;
                break;
            }
        rem=sum%3;
        // if above is done, then rem must be ok
        if(rem%3!=0){
            for(int k=0;k<2;++k)
                for(int i=0;i<3;++i)
                    if(cnt[n258[i]] > 0){
                        sum-=n258[i], cnt[n258[i]]--;
                        break;
                    }
        }
        rem=sum%3;
        // if successfully subtract twice, then rem must be ok
        if(rem%3!=0){
            cout<<-1<<endl;
            return 0;
        }
    }else{
        for(int i=0;i<3;++i)
            if(cnt[n258[i]] > 0){
                sum-=n258[i], cnt[n258[i]]--;
                break;
            }
        rem=sum%3;
        if(rem%3!=0){
            for(int k=0;k<2;++k)
                for(int i=0;i<3;++i)
                    if(cnt[n147[i]] > 0){
                        sum-=n147[i], cnt[n147[i]]--;
                        break;
                    }
        }
        rem=sum%3;
        if(rem%3!=0){
            cout<<-1<<endl;
            return 0;
        }
    }
    print();
    return 0;
}