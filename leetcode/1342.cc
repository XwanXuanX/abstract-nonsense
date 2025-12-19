#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        const int ki = king[0], kj = king[1];
        set<pair<int, int>> Qs;
        for (const auto& q : queens) {
            Qs.insert({q[0], q[1]});
        }
        vector<vector<int>> ans;
        // Up;
        for (int i = ki; i >= 0; --i) {
            if (Qs.count({i, kj})) {
                ans.push_back({i, kj});
                break;
            }
        }
        // Down;
        for (int i = ki; i < 8; ++i) {
            if (Qs.count({i, kj})) {
                ans.push_back({i, kj});
                break;
            }
        }
        // Left;
        for (int j = kj; j >= 0; --j) {
            if (Qs.count({ki, j})) {
                ans.push_back({ki, j});
                break;
            }
        }
        // Right;
        for (int j = kj; j < 8; ++j) {
            if (Qs.count({ki, j})) {
                ans.push_back({ki, j});
                break;
            }
        }
        // Up-left;
        for (int i = ki, j = kj; i >= 0 && j >= 0; i--, j--) {
            if (Qs.count({i, j})) {
                ans.push_back({i, j});
                break;
            }
        }
        // Up-right;
        for (int i = ki, j = kj; i >= 0 && j < 8; i--, j++) {
            if (Qs.count({i, j})) {
                ans.push_back({i, j});
                break;
            }
        }
        // Down-left;
        for (int i = ki, j = kj; i < 8 && j >= 0; i++, j--) {
            if (Qs.count({i, j})) {
                ans.push_back({i, j});
                break;
            }
        }
        // Down-right;
        for (int i = ki, j = kj; i < 8 && j < 8; i++, j++) {
            if (Qs.count({i, j})) {
                ans.push_back({i, j});
                break;
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)