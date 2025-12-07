#include <bits/stdc++.h>
using namespace std;

// This is the ArrayReader's API interface.
// You should not implement it, or speculate about its implementation
class ArrayReader {
public:
    // Compares the sum of arr[l..r] with the sum of arr[x..y]
    // return 1 if sum(arr[l..r]) > sum(arr[x..y])
    // return 0 if sum(arr[l..r]) == sum(arr[x..y])
    // return -1 if sum(arr[l..r]) < sum(arr[x..y])
    int compareSub(int l, int r, int x, int y);

    // Returns the length of the array
    int length();
};

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int n = reader.length();
        int l = 0, r = n - 1;
        while (l < r) {
            const int len = r - l + 1, h = len / 2;
            if (len % 2) {
                const int res = reader.compareSub(l, l + h - 1, l + h + 1, r);
                if (res == 1) {
                    r = l + h - 1;
                } else if (res == -1) {
                    l = l + h + 1;
                } else {
                    return l + h;
                }
            } else {
                const int res = reader.compareSub(l, l + h - 1, l + h, r);
                if (res == 1) {
                    r = l + h - 1;
                } else if (res == -1) {
                    l = l + h;
                } else {
                    assert(false);
                }
            }
        }
        assert(l == r);
        return l;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)