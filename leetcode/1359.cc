#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        unordered_set<int> V;
        V.insert(start);
        ans.push_back(start);
        for (int _ = 0; _ < (1 << n); ++_) {
            for (int i = 0; i < n; ++i) {
                const int nn = start ^ (1 << i);
                if (!V.count(nn)) {
                    V.insert(nn);
                    ans.push_back(nn);
                    start = nn;
                    break;
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)