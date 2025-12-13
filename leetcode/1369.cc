#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        const int n = s1.size();
        string a, b;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                a.push_back(s1[i]), b.push_back(s2[i]);
            }
        }
        assert(a.size() == b.size());
        if (a.size() % 2) {
            return -1;
        }
        int ans = 0, nx = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == 'x') {
                nx++;
            }
        }
        const int ny = a.size() - nx;
        return nx / 2 + ny / 2 + 2 * (nx % 2 && ny % 2);
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)