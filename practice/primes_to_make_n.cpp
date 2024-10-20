//You are given two numbers n, m. N is the target sum whcih you have to reach using the first m primes. You have to print the number of primes requierd to reach the sum.
//example n = 11, m = 3
//first 3 primes is 2, 3, 5. You can reach 11 with 3 + 3 + 5
//so the output is 3 because 3 numbers are used

#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

// Function to generate the first m prime numbers
vector<int> generatePrimes(int m) {
    vector<int> primes;
    int num = 2; // Start checking for primes from 2

    while (primes.size() < m) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }

    return primes;
}

int solve(int n, int m) {
    auto primes = generatePrimes(m);
    vector<long> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int prime: primes) {
            if (i >= prime) {
                dp[i] = min(dp[i], 1 + dp[i - prime]);
            }
        }
    }

    return dp[n];
}

int main() {
    int n = 11;
    int m = 3;
    cout << solve(n, m) << endl;
}

