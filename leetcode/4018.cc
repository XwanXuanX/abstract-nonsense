#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    static long long minMoves(vector<int>& balance) {
        const ll n = balance.size();
        const ll tot = accumulate(balance.begin(), balance.end(), 0ll);
        if (tot < 0) return -1;
        ll neg_pos = -1, ans = 0;
        for (ll i = 0; i < n; ++i) if (balance[i] < 0) neg_pos = i;
        if (neg_pos == -1) return 0;
        vector<ll> rotated;
        for (ll i = (neg_pos + 1) % n; i != neg_pos; i = (i + 1) % n) rotated.push_back(balance[i]);
        ll l = 0, r = rotated.size() - 1;
        while (l < r) {
            // Try left
            const ll transferred_left = min(abs(static_cast<ll>(balance[neg_pos])), rotated[l]);
            ans += (l + 1) * transferred_left;
            balance[neg_pos] += transferred_left;
            if (balance[neg_pos] >= 0) return ans;
            // Try right
            const ll transferred_right = min(abs(static_cast<ll>(balance[neg_pos])), rotated[r]);
            ans += (l + 1) * transferred_right;
            balance[neg_pos] += transferred_right;
            if (balance[neg_pos] >= 0) return ans;
            l++, r--;
        }
        // If we reach here, then the balance is still negative.
        // If we have an even number of positions, we would search every position already above
        assert(l == r && abs(balance[neg_pos]) <= rotated[l]);
        const ll transferred = min(abs(static_cast<ll>(balance[neg_pos])), rotated[l]);
        ans += (l + 1) * transferred;
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)