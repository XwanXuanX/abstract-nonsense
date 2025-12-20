#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        const int n = sticks.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto i : sticks) {
            pq.push(i);
        }
        int ans = 0;
        while (pq.size() > 1) {
            const int i = pq.top();
            pq.pop();
            const int j = pq.top();
            pq.pop();
            ans += (i + j);
            pq.push(i + j);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)