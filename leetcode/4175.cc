#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    // REMAINDER! MOD! CYCLES! REMEMBER!
    static int minAllOneMultiple(const int k) {
        unordered_set<int> rems;
        int rem = 0, ans = 0;
        do {
            ans++, rem = (rem * 10 + 1) % k;
            if (rem == 0) return ans;
            if (rems.count(rem)) return -1;
            rems.insert(rem);
        } while (true);
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)