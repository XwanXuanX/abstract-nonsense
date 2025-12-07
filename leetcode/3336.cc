#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange - 1;
            numExchange++, ans++;
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)