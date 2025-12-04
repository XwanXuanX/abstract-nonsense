#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        for (int p = 0; p < k; ++p) {
            vector<int> pow;
            pow.emplace_back(0);
            for (int i = p; i < n; i += k) {
                int prev = pow.back();
                pow.emplace_back(prev + energy[i]);
            }
            for (int i = 0; i < static_cast<int>(pow.size()) - 1; ++i) {
                ans = max(ans, pow.back() - pow[i]);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)