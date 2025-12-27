#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int minOperations(const vector<int>& nums) {
        const int n = nums.size();
        int non_distinct = 0;
        unordered_map<int, int> cnt;
        for (int i = n - 1; i >= 0; --i) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1) {
                non_distinct = i + 1;
                break;
            }
        }
        return ((non_distinct / 3) + (non_distinct % 3 != 0));
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)