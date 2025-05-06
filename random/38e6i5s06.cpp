#include <bits/stdc++.h>
using namespace std;

void getseg(vector<pair<int,int>>& seg, const string& s) {
    int start = 0;
    for (int i=1; i<s.size(); ++i) {
        if (s[i] != s[i-1]) {
            seg.push_back(make_pair(start, i-1));
            start = i;
        }
    }
    seg.push_back(make_pair(start, s.size()-1));
}

bool lenOk(pair<int,int>& p, pair<int,int>& s) {
    int lenp = p.second - p.first + 1;
    int lens = s.second - s.first + 1;
    return lens >= lenp && lens <= 2 * lenp;
}

void solve() {
    string p, s;
    cin>>p>>s;

    vector<pair<int,int>> pseg, sseg;
    getseg(pseg, p);
    getseg(sseg, s);

    // they should have the same length
    if (pseg.size() != sseg.size()) {
        cout<<"NO\n";
        return;
    }

    for (int i=0; i<pseg.size(); ++i) {
        auto& ps = pseg[i];
        auto& ss = sseg[i];
        // they should have the same type at least...
        if (p[ps.first] != s[ss.first]) {
            cout<<"NO\n";
            return;
        }
        // finally check the length...
        if (!lenOk(ps, ss)) {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while (tt--) {
        solve();
    }
}