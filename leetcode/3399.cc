#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * There are n^2 ways to remove any two numbers from nums1
     * After removing, checking the rest take O(n) time.
     * Total time complexity = O(n^3)
     */
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        const int n = nums1.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> removed;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j)
                        removed.push_back(nums1[k]);
                }
                assert(removed.size() == nums2.size());
                int invalid = false;
                for (int k = 1; k < removed.size(); ++k) {
                    if (nums2[k] - removed[k] != nums2[k - 1] - removed[k - 1]) {
                        invalid = true;
                        break;
                    }
                }
                if (!invalid) {
                    ans = min(ans, nums2[0] - removed[0]);
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)