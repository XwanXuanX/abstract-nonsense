#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(), a.end());
    vector<int> u(1, a.front());
    for(int i=1; i<n; ++i) if(a[i] != a[i-1]) u.push_back(a[i]);
    if(u.size() <= 3){
        cout<<fixed<<setprecision(6);
        cout<<0.0<<endl;
        int i=0;
        for(i=0; i<u.size(); ++i) cout<<(double)u[i]<<' ';
        if(i < 3) for(; i<3; ++i) cout<<(double)u.back()<<' ';
        return 0;
    }
    vector<int> diff;
    for(int i=1; i<u.size(); ++i) diff.push_back(u[i] - u[i-1]);
    for(int i=1; i<diff.size(); ++i) diff[i] += diff[i-1];
    double mind=1e18;
    double p1, p2, p3;
    for(int i=0; i<diff.size()-1; ++i){ // which requires the min array size to be 4
        int left=i+1, right=diff.size()-1;
        int minmx=LLONG_MAX, besti=0;
        while(left <= right){
            int mid=(left+right)/2;
            int lg = diff[mid-1] - diff[i], rg = diff.back() - diff[mid];
            if(max(lg,rg) < minmx){
                minmx = max(lg,rg);
                besti = mid;
            }
            if(lg > rg) right = mid-1;
            else left = mid+1;
        }
        int s1 = (i==0) ? 0 : diff[i-1];
        int s2 = diff[besti-1] - diff[i];
        int s3 = diff.back() - diff[besti];
        if((double)max({s1,s2,s3}) / 2 < mind){
            mind = min(mind, (double)max({s1,s2,s3}) / 2);
            p1 = ((double)(u[0] + u[i])) / 2;
            p2 = ((double)(u[i+1] + u[besti])) / 2;
            p3 = ((double)(u[besti+1] + u.back())) / 2;
        }
    }
    cout<<fixed<<setprecision(6);
    cout<<mind<<endl;
    cout<<p1<<' '<<p2<<' '<<p3<<endl;
    return 0;
}

/**
 * partition the array into 3 segments, such that the partial sum for each segment is minimum
 * fix one partition point, binary search for the other partition point s.t. the rest of the array is partitioned into two equal parts
 * 1 10001 10002 10003 10004
 * 10000 10001 10002 10003
 * 20 30 70 94
 */

/**
 * Tutorial is important
 * 358 final is cummulative (90% post midterm)
 * 9 questions:
 * 1. CSMA/CD (NOT CSMA/CA!!)
 * 2. know the terms: LAN, WLAN, wireless protocals
 * 3. be aware of the subnet: given a small network, write down network ID, prefix, ...
 * 4. term explanation: short questions 10 questions for 5 marks (name 3 types of switches)
 * 5. IP address summarization: 8 organization, what would be the advertise address (aggregation)
 * 6. basic principle of IP packets (e.g. reasons for IP packet drop)
 * 7. BGP policy (eBGP, iBGP)
 * 8. TCP rate calculation (direct mapping between window size and rate)
 * 9. TCP protocal, neet to interpret the TCP rate graph (graph in the lecture will probably be on the exam)
 */