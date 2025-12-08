#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        const int n = arr.size();
        double sum = 0;
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            sum += arr[i];
        }
        if (sum / k >= threshold) {
            ans++;
        }
        for (int l = 1, r = k; r < n; ++l, ++r) {
            sum += arr[r], sum -= arr[l - 1];
            if (sum / k >= threshold) {
                ans++;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)