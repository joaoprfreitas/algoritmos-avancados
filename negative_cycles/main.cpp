#include <iostream>
#include <vector>

using namespace std;

#define MAX_NODES 2501

typedef long long ll;

typedef pair<ll, ll> ii;
typedef vector<ii> vii;
vector<vii> AdjList(MAX_NODES);

int n, m, u, v;
ll w;

bool hasNegativeCycles() {
    vector<ll> dist(MAX_NODES, 1e18);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (int j = 0; j < (int) AdjList[u].size(); j++) {
                ii v = AdjList[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int j = 0; j < (int) AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second)
                return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
    }

    cout << (hasNegativeCycles() ? "YES" : "NO") << endl;

    return EXIT_SUCCESS;
}