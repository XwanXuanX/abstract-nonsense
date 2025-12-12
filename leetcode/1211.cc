#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class CombinationIterator {
public:
    vector<string> comb;
    int len = 0, ptr = 0;
    string path;

    void back(const string& s, const int i, const int n) {
        if (path.size() == len) {
            comb.push_back(path);
            return;
        }
        if (i == n) {
            return;
        }
        // Include
        path.push_back(s[i]);
        back(s, i + 1, n);
        // Exclude
        path.pop_back();
        back(s, i + 1, n);
    }

    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength;
        back(characters, 0, characters.size());
    }
    
    string next() {
        const auto ans = comb[ptr];
        ptr++;
        return ans;
    }
    
    bool hasNext() {
        return ptr != comb.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//IMPORTANT!! Submit Code Region End(Do not remove this line)