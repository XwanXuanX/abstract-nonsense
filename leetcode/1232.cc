#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        arr.push_back(0);
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        int pfs = 0, ans = 0, diff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            const int lb = arr[i - 1], rb = arr[i] - 1;
            const int rest = n - i;
            for (int j = lb; j <= rb; ++j) {
                const int res = pfs + j * rest;
                if (abs(res - target) < diff) {
                    diff = abs(res - target);
                    ans = j;
                }
            }
            pfs += arr[i];
        }
        if (pfs <= target)
            return arr.back();
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)