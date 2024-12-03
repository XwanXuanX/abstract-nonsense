#include <bits/stdc++.h>
using namespace std;
#define int long long

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};

const int N = 1e6 + 10;
int ans[N];

void merge(vector<pair<int,int>>& a, int start, int mid, int end){
    int n = mid-start+1, m = end-mid;
    pair<int,int> f[n], s[m];

    for(int i=start; i<=mid; ++i)
        f[i - start] = a[i];
    for(int i=mid+1; i<=end; ++i)
        s[i - mid - 1] = a[i];

    int i=0, j=0, k=start, cnt=0;

    while(i<n && j<m){
        if (f[i].second <= s[j].second){
            ans[f[i].first] += cnt;
            a[k++] = f[i++];
        }else{
            cnt++;
            a[k++] = s[j++];
        }
    }

    while(i < n){
        ans[f[i].first] += cnt;
        a[k++] = f[i++];
    }

    while(j < m){
        a[k++] = s[j++];
    }
}

void mergeSort(vector<pair<int,int>>& item, int low, int high){
    if(low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(item, low, mid);
    mergeSort(item, mid+1, high);
    merge(item, low, mid, high);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    for(int i=0; i<n; ++i){
        int t; cin>>t;
        a[i].second = b[i] = t;
        a[i].first = i;
    }

    mergeSort(a, 0, n-1); // O(nlogn)

    map<int,int> cnt;
    for(int i=0; i<n; ++i)
        cnt[b[i]] = ans[i];

    vector<int> pfs, ele;
    for(auto& p:cnt)
        pfs.push_back(p.second), ele.push_back(p.first);
    
    int res=0;
    FenwickTree ftree(pfs);

    for(int i=0; i<n; ++i){
        auto it = lower_bound(ele.begin(), ele.end(), b[i]);
        int idx = it - ele.begin();
        if(idx > 0)
            res += ftree.sum(idx-1);
        ftree.add(idx, -ans[i]);
    }

    cout<<res<<endl;
    return 0;
}

/**
 * well... this problem can easily be solved using dp in O(n^2) time
 * if we can find all the decreasing subsequences, then we know the answer
 * we don't need to find the subsequences exactly, just know how many of them
 * 10 9 5 6 8 3 4 7 11
 *  7 6 2 2 3 0 0 0 0
 * 13 + 7 = 20
 */