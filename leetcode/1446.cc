#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static constexpr double small = static_cast<double>(360) / 60;
    static constexpr double large = static_cast<double>(360) / 12;

    double angleClock(int hour, int minutes) {
        const double mni = small * minutes;
        const double hur = large * hour + large * (minutes / static_cast<double>(60));
        double ang = mni - hur;
        if (ang < 0) {
            ang += 360;
        }
        return min(ang, 360 - ang);
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)