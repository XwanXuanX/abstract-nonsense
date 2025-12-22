#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;
        int max3 = INT_MIN, min3 = INT_MAX;
        int max4 = INT_MIN, min4 = INT_MAX;
        for (int i = 0, n = arr1.size(); i < n; ++i) {
            const int a = arr1[i], b = arr2[i];
            int v1 = a + b + i, v2 = a - b + i, v3 = -a + b + i, v4 = -a - b + i;
            max1 = max(max1 , v1), min1 = min(min1 , v1);
            max2 = max(max2 , v2), min2 = min(min2 , v2);
            max3 = max(max3 , v3), min3 = min(min3 , v3);
            max4 = max(max4 , v4), min4 = min(min4 , v4);
        }
        int d1 = max1 - min1, d2 = max2 - min2, d3 = max3 - min3, d4 = max4 - min4;
        return max({d1, d2, d3, d4});
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)