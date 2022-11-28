#include <iostream>
#include <cstring>

using namespace std;

#define MAX_MOUNTAINS 100000

int n;
int h[MAX_MOUNTAINS + 1];
int costs[MAX_MOUNTAINS + 1];

int minCost(int i) {
    if (i == n) return 0;
    if (costs[i] != -1) return costs[i];

    int cost = minCost(i + 1) + abs(h[i] - h[i + 1]);

    if (i + 2 <= n)
        cost = min(cost, minCost(i + 2) + abs(h[i] - h[i + 2]));

    costs[i] = cost;

    return cost;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    memset(costs, -1, sizeof(costs));

    cout << minCost(1) << endl;

    return EXIT_SUCCESS;
}