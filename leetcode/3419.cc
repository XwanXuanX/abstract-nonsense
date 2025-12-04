#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * For a point to be in the square of side s, then |x| <= s && |y| <= s
     * For each point, compute the largest square that can hold them
     * Then group points based on the square length
     */
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        map<int, vector<char>> sqs;
        for (int i = 0; i < n; ++i) {
            int sq = max(abs(points[i][0]), abs(points[i][1]));
            char lab = s[i];
            sqs[sq].emplace_back(lab);
        }
        unordered_set<char> seen;
        int ans = 0;
        for (auto& p : sqs) {
            for (auto& c : p.second) {
                if (seen.count(c)) {
                    return ans;
                }
                seen.insert(c);
            }
            ans += p.second.size();
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)