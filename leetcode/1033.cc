#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int brokenCalc(int startValue, const int target) {
        if (startValue >= target) {
            return startValue - target;
        }
        int time2 = 0;
        while (startValue < target) {
            startValue *= 2;
            time2++;
        }
        const int sub = startValue - target;
        int time1 = sub & 1;
        for (int i = 1; i < 31; ++i) {
            if (sub & (1 << i)) {
                time1 += (1 << max(i - time2, 0));
            }
        }
        return time2 + time1;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)