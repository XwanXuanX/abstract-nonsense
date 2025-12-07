#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minFlips(string target) {
        const int n = target.size();
        int f1 = 0;
        for (f1 = 0; f1 < n; ++f1) {
            if (target[f1] == '1')
                break;
        }
        if (f1 == n) {
            return 0;
        }
        int ans = 1;
        for (int i = f1 + 1; i < n; ++i) {
            if (target[i] != target[i - 1])
                ans++;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)