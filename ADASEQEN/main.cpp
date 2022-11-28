#include <iostream>
#include <cstring>

using namespace std;

#define MAX 2025

int n, m;
int cost[MAX];
int MEMO[MAX][MAX];
string s1, s2;

int LCS() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s1[i - 1] == s2[j - 1])
                MEMO[i][j] = MEMO[i - 1][j - 1] + cost[int(s1[i - 1])];
            else
                MEMO[i][j] = max(MEMO[i][j - 1], MEMO[i - 1][j]);
        }
    }

    return MEMO[n][m];
}

int main() {
    cin >> n >> m;

    for (int i = 'a'; i <= 'z'; i ++)
        cin >> cost[i];
    
    cin >> s1 >> s2;
    
    cout << LCS() << endl;
    
    return EXIT_SUCCESS;
}
