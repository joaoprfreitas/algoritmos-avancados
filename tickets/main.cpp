#include <iostream>
#include <cstring>

using namespace std;

#define MAX_DAYS 300

int d[MAX_DAYS + 1];
int n, x, y, z;
int costs[MAX_DAYS + 1];

int minCost() {
    costs[0] = 0;

    for (int i = 1; i <= MAX_DAYS; i++) {
        if (costs[i] == -1)
            costs[i] = costs[i - 1]; // propagate the cost of the previous day
        else {
            int cur = costs[i - 1] + x; // yesterday min price + 1 day pass
            cur = min(cur, y + costs[max(0, i - 7)]); // 7 days ago min price + 7 day pass
            cur = min(cur, z + costs[max(0, i - 30)]); // 30 days ago min price + 30 day pass
            costs[i] = cur;
        }
    }

    return costs[d[n]];
}

int main () {
    cin >> n;
    cin >> x >> y >> z;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    memset(costs, -1, sizeof(costs));

    for (int day : d) // initialize the days we need to travel
        costs[day] = 0;

    cout << minCost() << endl;

    return EXIT_SUCCESS;
}