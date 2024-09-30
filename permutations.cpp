#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const __uint128_t MOD = 1e9 + 7;

// Function to convert unsigned __uint128_t to string
string uint128_to_string(__uint128_t value) {
    if (value == 0) return "0";
    std::string result;
    while (value > 0) {
        result += '0' + (value % 10);
        value /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to compute x^y mod MOD
__uint128_t mod_pow(__uint128_t x, __uint128_t y, __uint128_t mod) {
    __uint128_t result = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            result = (result * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return result;
}

// Function to compute modular inverse of a mod MOD
__uint128_t mod_inv(__uint128_t a, __uint128_t mod) {
    return mod_pow(a, mod - 2, mod);
}

// Precompute factorials and inverses up to n
void compute_factorials(int n, vector<__uint128_t>& factorial, vector<__uint128_t>& inv_factorial) {
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    factorial[n] = factorial[n] % MOD;
    inv_factorial[n] = mod_inv(factorial[n], MOD);
    for (int i = n - 1; i >= 1; --i) {
        inv_factorial[i] = (inv_factorial[i + 1] * (i + 1)) % MOD;
    }
}

// Function to compute the number of unique anagrams
__uint128_t count_unique_anagrams(const string& s) {
    int n = s.length();
    unordered_map<char, int> char_count;
    for (char c : s) {
        char_count[c]++;
    }

    // Precompute factorials and inverses
    vector<__uint128_t> factorial(n + 1);
    vector<__uint128_t> inv_factorial(n + 1);
    compute_factorials(n, factorial, inv_factorial);

    // Calculate the denominator
    __uint128_t denominator = 1;
    for (const auto& pair : char_count) {
        int count = pair.second;
        denominator = (denominator * factorial[count]) % MOD;
    }

    // Calculate the result
    __uint128_t result = (factorial[n] * mod_inv(denominator, MOD)) % MOD;
    return result;
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        if (s.empty())
            break;
        __uint128_t num_anagrams = count_unique_anagrams(s);
        cout << uint128_to_string(num_anagrams) << endl;
    }
    return 0;
}
