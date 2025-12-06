#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * All numbers in nums must have at least the same bits as x
     * The smallest number is x, so the array should start with x
     * 111 -> 1111 -> 11111 -> ...
     * 100 -> 101 -> 110 -> 111 -> 1100 -> 1101 -> ...
     * 1001 -> 1011 -> 1101 -> 1111 -> 11001 -> ...
     */
    using ll = long long;

    long long minEnd(int n, int x) {
        vector<int> bits, lb;
        for (int i = 0; i < 31; ++i) {
            bits.push_back(x & (1 << i));
        }
        for (int i = 0; i < 31; ++i) {
            lb.push_back((n - 1) & (1 << i));
        }
        int id = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i] == 0) {
                bits[i] = lb[id++];
            }
        }
        for (int i = id; i < lb.size(); ++i) {
            bits.push_back(lb[i]);
        }
        ll ans = 0;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i]) {
                ans |= (1ll << i);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)