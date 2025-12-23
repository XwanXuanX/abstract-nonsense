#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    unordered_map<int, unordered_map<int, double>> dp;

    static bool has_decimal(const double x) {
        return std::fabs(x - std::round(x)) > 1e-9;
    }

    double dfs(const vector<double>& a, const int i, const int target) {
        const int n = a.size();
        if (i == n) {
            return dp[i][target] = target == 0 ? 0 : -1;
        }
        if (dp.count(i) && dp[i].count(target)) {
            return dp[i][target];
        }
        double down = -1, up = -1;
        const int i_part = static_cast<int>(a[i]);
        const int j_part = i_part + 1;
        if (target - i_part >= 0) {
            down = dfs(a, i + 1, target - i_part);
        }
        if (has_decimal(a[i]) && target - j_part >= 0) {
            up = dfs(a, i + 1, target - j_part);
        }
        if (down == -1 && up == -1) {
            return dp[i][target] = -1;
        }
        down = down == -1 ? 1e9 : down;
        up = up == -1 ? 1e9 : up;
        const auto lr = abs(a[i] - i_part) + down;
        const auto rr = abs(a[i] - j_part) + up;
        return dp[i][target] = min(lr, rr);
    }

    string minimizeError(vector<string>& prices, int target) {
        const int n = prices.size();
        vector<double> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = stod(prices[i]);
        }
        const auto res = dfs(a, 0, target);
        if (res == -1) {
            return "-1";
        }
        ostringstream oss;
        oss << std::fixed << std::setprecision(3) << res;
        return oss.str();
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)