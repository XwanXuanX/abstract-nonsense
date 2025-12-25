#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        const int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int pfs = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            pfs += nums[i];
            const int rem = (pfs % k) < 0 ? (pfs % k) + k : pfs % k;
            ans += cnt[rem];
            cnt[rem]++;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)