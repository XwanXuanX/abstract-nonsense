#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans;

    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(),
                                  arr[i])
                      - ans.begin();

            ans[low] = arr[i];
        }
    }

    return ans.size();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << lengthOfLIS(a) << '\n';
}