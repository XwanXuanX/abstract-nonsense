#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        vector<unsigned char> ba, bb, bc;
        for (int i = 0; i < 31; ++i) {
            ba.push_back((a >> i) & 1);
            bb.push_back((b >> i) & 1);
            bc.push_back((c >> i) & 1);
        }
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            const unsigned char res = ba[i] | bb[i];
            if (res == 0 && bc[i] == 1) {
                ans++;
            } else if (res == 1 && bc[i] == 0) {
                ans += (ba[i] == 1 && bb[i] == 1 ? 2 : 1);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)