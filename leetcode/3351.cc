#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    using ll = long long;

    static long long maximumHappinessSum(vector<int>& happiness, int k) {
        const ll n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<ll>());
        queue<ll> q;
        for (const auto h : happiness) {
            q.push(h);
        }
        ll selected = 0, ans = 0;
        while (k && q.size() && q.front() > selected) {
            ans += q.front() - selected;
            q.pop(), k--, selected++;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)