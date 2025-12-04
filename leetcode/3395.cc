#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    /*
     * let l = t.size(), there exists k s.t. l * k = n, in other words,
     * the length of t must be a divisor of length of s
     */
    vector<int> divs(const int n) {
        vector<int> d;
        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                if (n / i == i)
                    d.push_back(i);
                else
                    d.push_back(i), d.push_back(n / i);
            }
        }
        return d;
    }

    int minAnagramLength(string s) {
        const int n = s.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            int id = s[i] - 'a';
            cnt[i][id]++;
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < n; ++j) {
                cnt[j][i] += cnt[j - 1][i];
            }
        }
        auto ds = divs(n);
        sort(ds.begin(), ds.end());
        for (auto& d : ds) {
            bool ok = true;
            vector<int> ref = cnt[d - 1];
            for (int i = 2 * d - 1; i < n; i += d) {
                vector<int> chk = cnt[i];
                for (int j = 0; j < 26; ++j) {
                    chk[j] -= cnt[i - d][j];
                }
                if (chk != ref) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return d;
            }
        }
        return -1;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)