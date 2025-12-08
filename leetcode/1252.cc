#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int n = palindrome.size();
        if (n == 1) {
            return {};
        }
        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)