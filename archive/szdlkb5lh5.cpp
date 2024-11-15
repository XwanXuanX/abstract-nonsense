#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define double long double

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> x(n), v(n);
    for(int i=0;i<n;++i)
        cin>>x[i];
    for(int i=0;i<n;++i)
        cin>>v[i];
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;++i)
        a[i] = make_pair(x[i], v[i]);
    
    // sort on the coordinates
    sort(a.begin(), a.end(), [](auto& p, auto& q){return p.first < q.first;});

    // x_start <= y_end && y_start <= x_end
    auto overlap=[&](auto& x, auto& y)->bool{ return x.first <= y.second && y.first <= x.second; };

    // check if a meet up is possible
    auto check=[&](double time)->bool{
        // two people at the end must move inward
        double lmove = a.front().first + (a.front().second * time);
        double rmove = a.back().first - (a.back().second * time);
        if(lmove < rmove)
            return false;
        
        pair<double, double> range = make_pair(rmove, lmove);
        // now check to see if all others can enter the range
        // and update the range accordingly
        for(int i=1;i<n-1;++i){
            double move = a[i].second * time;
            pair<double,double> pos = make_pair(a[i].first - move, a[i].first + move);
            if(!overlap(range, pos))
                return false;
            // update the range with pos
            range.first = max(range.first, pos.first);
            range.second = min(range.second, pos.second);
        }

        return true;
    };

    double left=0.0f, right=1e18f;
    for(int i=0; i < 100 && left + 0.000000001 < right; ++i){
        double mid = left + (right - left) / 2;
        if(check(mid))
            right=mid;
        else
            left=mid; 
    }

    cout<<setprecision(13)<<left<<endl;
    return 0;
}

/**
 * it's always better to use maximum speed
 * binary search on the time. for each time, we can compute the distance each can move
 * then we check if they can all meet up.
 * 
 * how to check the meet up efficiently? 
 */