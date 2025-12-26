#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static vector<int> prisonAfterNDays(vector<int>& cells, const int n) {
        auto update = [&] {
            vector<int> _cells = cells;
            _cells[0] = _cells[7] = 0;
            for (int i = 1; i <= 6; ++i) {
                _cells[i] = (cells[i - 1] && cells[i + 1]) || (!cells[i - 1] && !cells[i + 1]);
            }
            cells.swap(_cells);
        };
        vector<vector<int>> loop = {cells};
        map<vector<int>, int> seen = {{cells, 0}};
        int rep_start = 0;
        for (int i = 1; i <= 64; ++i) {
            update();
            if (seen.count(cells)) {
                rep_start = seen[cells];
                break;
            }
            seen[cells] = i, loop.push_back(cells);
        }
        const int no_rep = rep_start, rep = loop.size() - no_rep;
        return loop[((n - no_rep) % rep) + rep_start];
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)