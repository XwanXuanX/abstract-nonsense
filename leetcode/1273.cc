#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static int f(const string& s) {
        map<char, int> cnt;
        for (const auto c : s) {
            cnt[c]++;
        }
        return cnt.begin()->second;
    }

    static int bs(const vector<int>& a, const int target) {
        int l = 0, r = a.size() - 1, ans = -1;
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (a[mid] > target) {
                r = mid - 1;
            } else {
                ans = max(ans, mid);
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        const int n = words.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = f(words[i]);
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (const string& q : queries) {
            const int target = f(q), ind = bs(a, target);
            ans.push_back(n - ind - 1);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)