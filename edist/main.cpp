#include <iostream>

using namespace std;

#define MAX_LENGTH 2000

int T;
string s1, s2;
int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];

int minOperations() {
    int n = s1.length();
    int m = s2.length();

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[n][m];
}

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> s1 >> s2;
        cout << minOperations() << endl;
    }

    return EXIT_SUCCESS;
}