#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int closest(int n, int& k) {
        const int d1 = n % 26, d2 = (-n + 26) % 26;
        if (min(d1, d2) <= k) {
            k -= min(d1, d2);
            return 0;
        }
        const int small = n - k;
        k = 0;
        return small;
    }

    string getSmallestString(string s, int k) {
        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            s[i] = closest(s[i] - 'a', k) + 'a';
            if (k == 0)
                break;
        }
        return s;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)