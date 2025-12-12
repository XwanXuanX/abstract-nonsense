#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int num[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 0; i < 9; ++i) {
            int n = 0;
            for (int j = i; j < 9; ++j) {
                n = n * 10 + num[j];
                if (low <= n && n <= high) {
                    ans.push_back(n);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)