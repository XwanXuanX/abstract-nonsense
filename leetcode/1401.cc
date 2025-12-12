#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        const int n = cheeseSlices;
        int l = 0, r = n;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            const int tot = mid * 4 + (n - mid) * 2;
            if (tot == tomatoSlices) {
                return {mid, n - mid};
            } else if (tot < tomatoSlices) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return {};
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)