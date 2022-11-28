#include <iostream>
#include <vector>

using namespace std;

#define MAX 2500

int n;
vector<int> MEMO(MAX, -1);

int lis(vector<int>& a, int i) {
    if (i == 0) return 1;
    if (MEMO[i] != -1) return MEMO[i];

    int biggest = 1;
    for (int j = i - 1; j >= 0; j--) {
        int value = lis(a, j) + 1;
        if (a[i] > a[j])
            biggest = max(value, biggest);
    }

    MEMO[i] = biggest;

    return MEMO[i];
}

int main() {
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << lis(a, n - 1) << endl;

    return EXIT_SUCCESS;
}