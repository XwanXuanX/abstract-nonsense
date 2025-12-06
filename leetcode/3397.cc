#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        const int mn1 = *min_element(nums1.begin(), nums1.end());
        const int mn2 = *min_element(nums2.begin(), nums2.end());
        return mn2 - mn1;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)