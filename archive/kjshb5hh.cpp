#include <bits/stdc++.h>
using namespace std;
#define int long long 

// get the next tenth of a number
int next_ten(int n){
    string front = to_string(n);
    if(front.size() == 1)
        return 10;
    return (stoi(front.substr(0, front.size()-1)) + 1) * 10;
}

int calc_rating(vector<int>& a){
    int rating=0;
    for(int i=0;i<a.size();++i)
        rating += (a[i] / 10);
    return rating;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    // we need to prioritize the filling of small difference
    vector<pair<int,int>> diff;
    for(int i=0;i<n;++i){
        if(a[i] == 100)
            continue;
        int next=next_ten(a[i]);
        diff.push_back(make_pair(next-a[i], i));
    }
    sort(diff.begin(), diff.end(), [](pair<int,int>& p, pair<int,int>& q){return p.first < q.first;});

    bool abort=false;
    for(int i=0;i<diff.size();++i){
        if(diff[i].first > k){
            abort=true;
            break;
        }
        a[diff[i].second] += diff[i].first;
        k -= diff[i].first;
    }

    // exe this if you cannot make any progress
    if(abort || k < 10){
        cout<<calc_rating(a)<<endl;
        return 0;
    }

    int rest=(k/10) * 10;
    for(int i=0;i<a.size();++i){
        int rem = 100 - a[i];
        if(rem > rest){
            a[i] += rest;
            break;
        }
        a[i] += rem;
        rest -= rem;
    }

    cout<<calc_rating(a)<<endl;
    return 0;
}

/**
 * clearly, you can only affect the overall rating if you can change the tenth digit
 * otherwise, the points are wasted.
 * so it's always more optimal to improve the skill that has a non-zero last digit
 * do that first and then decide on the remaining points
 * 90  90  90  90  90  90  90
 * 100 100 100 100 100 100 100 80 10 
 */