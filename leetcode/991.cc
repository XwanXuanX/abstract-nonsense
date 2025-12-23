#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    struct comp {
        bool operator()(const int a, const int b) const {
            return pair<int, int>{abs(a), a} < pair<int, int>{abs(b), b};
        }
    };

    bool canReorderDoubled(vector<int>& arr) {
        const int n = arr.size();
        unordered_map<int, int> odds;
        map<int, int, comp> evens;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2) {
                odds[arr[i]] += 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 == 0) {
                const auto half = arr[i] / 2;
                if (odds.count(half)) {
                    odds[half] -= 1;
                    if (odds[half] == 0)
                        odds.erase(half);
                } else {
                    evens[arr[i]] += 1;
                }
            }
        }
        if (odds.size()) {
            return false;
        }
        while (evens.size()) {
            const auto large = evens.rbegin();
            const auto half = large->first / 2;
            if (large->first == half) {
                if (large->second % 2) {
                    return false;
                }
                evens.erase(large->first);
            } else {
                if (!evens.count(half) || evens[half] < large->second) {
                    return false;
                }
                assert(evens.size() >= 2);
                if (evens[half] == large->second) {
                    evens.erase(half);
                } else {
                    evens[half] -= large->second;
                }
                evens.erase(large->first);
            }
        }
        return true;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)