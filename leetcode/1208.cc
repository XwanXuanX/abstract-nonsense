#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        const int n = seq.size();
        int s1 = 0, s2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                if (s1 < s2)
                    s1++, ans.push_back(0);
                else
                    s2++, ans.push_back(1);
            } else {
                if (s1 < s2)
                    s2--, ans.push_back(1);
                else
                    s1--, ans.push_back(0);
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)