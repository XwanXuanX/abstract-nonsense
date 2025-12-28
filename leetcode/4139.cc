#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int rev(const int n) {
        string sn = to_string(n);
        reverse(sn.begin(), sn.end());
        return stoi(sn);
    }

    static int minMirrorPairDistance(const vector<int>& nums) {
        const int n = nums.size();
        int ans = 1e9;
        unordered_map<int, int> ocr;
        for (int i = 0; i < n; ++i) {
            const int nj = nums[i], ni = rev(nj);
            if (ocr.count(nj)) ans = min(ans, abs(ocr[nj] - i));
            ocr[ni] = max(ocr[ni], i);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)