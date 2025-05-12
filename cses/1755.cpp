#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    map<char, int> cnt;
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]]++;
    }
    int odd = 0;
    for (auto& p : cnt) {
        if (p.second % 2) {
            odd++;
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    string prefix, middle, suffix;
    for (auto& p : cnt) {
        if (p.second % 2) {
            for (int i = 0; i < p.second; ++i) {
                middle.push_back(p.first);
            }
        } else {
            for (int i = 0; i < p.second / 2; ++i) {
                prefix.push_back(p.first);
                suffix.push_back(p.first);
            }
        }
    }

    reverse(prefix.begin(), prefix.end());
    cout << (prefix + middle + suffix) << '\n';
}