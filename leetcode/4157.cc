#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static bool isVowel(char c) { return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}

    static string reverseWords(string s) {
        stringstream ss(s);
        string word, res;
        int target = -1;
        while (ss >> word) {
            int cnt = 0;
            for (char c : word) cnt += isVowel(c);
            if (target == -1) target = cnt;
            else if (cnt == target) reverse(word.begin(), word.end());
            res += (res.empty() ? "" : " ") + word;
        }
        return res;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)