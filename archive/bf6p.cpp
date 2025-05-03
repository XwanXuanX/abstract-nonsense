#include <bits/stdc++.h>
using namespace std;

void printResult(int alice, int bob) {
    if (alice > bob) {
        cout << "BOB\n";
    } else if (alice < bob) {
        cout << "ALICE\n";
    } else {
        cout << "DRAW\n";
    }
}

void solve() { 
    int n;
    string s;
    cin >> n >> s;
    int n0 = 0;
    for (int i=0; i<n; ++i) {
        n0 += (s[i] == '0');
    }
    // if the number of 0s is even
    // then means the middle element is not 0 for odd
    if (n0 % 2 == 0) {
        n0 /= 2;
        int alice = (int)ceil((double)n0 / 2);
        int bob = n0 / 2;
        printResult(alice, bob);
        return;
    }
    // if the number of 0s is odd
    if (n0 == 1) {
        cout << "BOB\n";
        return;
    }
    n0 /= 2;
    int alice = (n0 / 2) + 1;
    int bob = (int)ceil((double)n0 / 2) + 1;
    printResult(alice, bob);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

/**
 * 1st move must be turn on one bit, alice at least pay 1 dollar
 * and it's best if alice can make the string once again a palindrome, forcing bob to pay 1 dollar
 * otherwise, bob can get away with 0 dollar, and alice has to pay another dollar.
 * O: 100000001
 * A: 100010001 (+1)
 * B: 100110001 (+1)
 * A: 100011001
 * B: 100111001 (+1)
 * A: 101111001 (+1)
 * B: 100111101
 * A: 101111101 (+1)
 * B: 111111101 (+1)
 * A: 101111111
 * B: 111111111 (+1)
 * 
 * O: 1001001
 * A: 1011001 (+1)
 * B: 1001101
 * A: 1011101 (+1)
 * B: 1111101 (+1)
 * A: 1011111
 * B: 1111111 (+1)
 * 
 * A: 0100 (a1)
 * B: 0010
 * A: 0110 (a1)
 * B: 1110 (b1)
 * A: 0111
 * B: 1111 (b1)
 */