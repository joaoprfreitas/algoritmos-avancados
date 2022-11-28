#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<int> primes;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    
    return true;
}

void sieve(int range) {
    for (int i = 2; i < range; i++)
        if (isPrime(i)) primes.push_back(i);
}

int getPowers(int n, int p) {
    int res = 0;
    for (int power = p; power <= n; power *= p)
        res += n / power;

    return res;
}

bool solve(int n, int m) {
    if (m == 0) return false;
    if (n >= m) return true;

    int k = m;
    vii factors;
    for (int i = 0; i < (int) primes.size(); i++) {
        if (primes[i] > k) break;
        
        int count = 0;
        while (k % primes[i] == 0) {
            count += 1;
            k = k / primes[i];
        }

        if (count > 0)
            factors.push_back(ii(primes[i], count));
    }

    if (k > 1) { // k is a prime
        if (n < k) return false;

        factors.push_back(ii(k, 1));
    }

    for (int i = 0; i < (int) factors.size(); i++)
        if (factors[i].second > getPowers(n, factors[i].first))
            return false;
    
    return true;
} 

int main() {
    int a, b;
    sieve(50000);
    while (cin >> a >> b) {

        if (solve(a, b)) {
            cout << b << " divides " << a << "!" << endl;
        } else {
            cout << b << " does not divide " << a << "!" << endl;
        }
    }

    return EXIT_SUCCESS;
}