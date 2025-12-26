#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static vector<string> spellchecker(const vector<string>& wordlist, const vector<string>& queries) {
        auto lower = [](string s) -> string {
            transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
                return tolower(c);
            });
            return s;
        };
        unordered_set<int> pos = {'a', 'e', 'i', 'o', 'u'};
        auto mask = [&](string s) -> string {
            s = lower(s);
            transform(s.begin(), s.end(), s.begin(), [pos](unsigned char c) {
                if (pos.count(c)) return static_cast<unsigned char>('*');
                return c;
            });
            return s;
        };
        unordered_set<string> original(wordlist.begin(), wordlist.end());
        unordered_map<string, string> capital;
        for (const auto& s : wordlist) {
            const string lo = lower(s);
            if (!capital.count(lo)) {
                capital[lo] = s;
            }
        }
        unordered_map<string, string> vowels;
        for (const auto& s : wordlist) {
            const string mk = mask(s);
            if (!vowels.count(mk)) {
                vowels[mk] = s;
            }
        }
        vector<string> ans;
        for (const auto& q : queries) {
            if (original.count(q)) {
                ans.push_back(q);
            } else if (capital.count(lower(q))) {
                ans.push_back(capital[lower(q)]);
            } else if (vowels.count(mask(q))) {
                ans.push_back(vowels[mask(q)]);
            } else {
                ans.push_back({});
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)