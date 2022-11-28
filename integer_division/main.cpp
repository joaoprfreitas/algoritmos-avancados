#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
	int a, b, res;
    
	while (scanf("%d %d", &a, &b), a) {
		res = abs(a - b);
        a = b;
		while (scanf("%d", &b), b) {
			res = gcd(res, abs(a - b));
			a = b;
		}
        cout << res << endl;
	}

	return EXIT_SUCCESS;
}