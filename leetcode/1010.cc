#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = unsigned long long;

    static vector<int> powerfulIntegers(const int x, const int y, const int bound) {
        if (x == 1 && y == 1) {
            return 2 <= bound ? vector<int>{2} : vector<int>{};
        }
        unordered_set<ll> ans;
        if (x == 1) {
            for (ll p = 0; p <= 20; ++p) {
                const ll can = pow(y, p);
                if (can > bound || can + 1 > bound) break;
                ans.insert(can + 1);
            }
            return vector<int>(ans.begin(), ans.end());
        }
        if (y == 1) {
            for (ll p = 0; p <= 20; ++p) {
                const ll can = pow(x, p);
                if (can > bound || can + 1 > bound) break;
                ans.insert(can + 1);
            }
            return vector<int>(ans.begin(), ans.end());
        }
        for (ll px = 0; px <= 20; ++px) {
            const ll can_x = pow(x, px);
            if (can_x >= bound) break;
            for (ll py = 0; py <= 20; ++py) {
                const ll can_y = pow(y, py);
                if (can_y >= bound || can_x + can_y > bound) break;
                ans.insert(can_x + can_y);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)