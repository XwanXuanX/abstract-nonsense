#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,x,y;
    cin>>n;
    vector<int> top, bot;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        if(y)
            top.push_back(x);
        else
            bot.push_back(x);
    }

    sort(top.begin(), top.end());
    sort(bot.begin(), bot.end());

    int ans=0;
    for(int i=0;i<top.size();++i){
        int x=top[i];
        auto it=lower_bound(bot.begin(), bot.end(), x);
        if(it == bot.end()) // all values in bot is smaller than x
            break;
        if(*it == x){ // we found a vertical line
            int j = it - bot.begin();
            int top_l = i, top_r = top.size() - i - 1, bot_l = j, bot_r = bot.size() - j - 1;
            ans = ans + top_l + top_r + bot_l + bot_r; 
        }
    }

    // now find other types of triangles
    // for each vertex x, if on the opposite side, there exists x-1 and x+1, then ok
    for(int i=0;i<top.size();++i)
        if(binary_search(bot.begin(),bot.end(),top[i]-1) && binary_search(bot.begin(),bot.end(),top[i]+1))
            ans++;
    for(int i=0;i<bot.size();++i)
        if(binary_search(top.begin(),top.end(),bot[i]-1) && binary_search(top.begin(),top.end(),bot[i]+1))
            ans++;

    cout<<ans<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

/**
 * must have y = 0 and y = 1 to form a triangle
 * the key is to locate the vertical line, and use combinatorics to find the answer in constant time
 */