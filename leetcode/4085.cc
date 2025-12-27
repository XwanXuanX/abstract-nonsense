#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    static vector<bool> primes_up_to(const int N) {
        if (N < 2) return {};
        vector<bool> is_prime(N + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 4; i <= N; i += 2) is_prime[i] = false;
        for (int i = 3; i * i <= N; i += 2) {
            if (is_prime[i]) {
                for (int j = i * i; j <= N; j += 2 * i) {
                    is_prime[j] = false;
                }
            }
        }
        return is_prime;
    }

    static int largestPrime(const int n) {
        const auto& is_prime = primes_up_to(n + 100);
        vector<int> primes = {2};
        for (int i = 3; i <= n + 100; i += 2) if (is_prime[i]) primes.push_back(i);
        int acc = 0, ans = 0;
        for (const auto p : primes) {
            acc += p;
            if (acc > n) break;
            if (is_prime[acc]) ans = max(ans, acc);
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)