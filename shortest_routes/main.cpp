#include <iostream>
#include <vector>

using namespace std;

#define INF 1e18
#define MAX_SIZE 501

typedef long long ll;
typedef pair<ll, ll> ii; // pair <node, weight>
typedef vector<ii> vii; // vector of pairs
vector<vii> AdjList(MAX_SIZE); // Adjacency list

ll c, dist[MAX_SIZE][MAX_SIZE]; // dist[i][j] = shortest path from i to j
int n, m, q, a, b; // cities, roads and queries

void floydWarshall() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) AdjList[i].size(); j++) {
            ii pair = AdjList[i][j];
            int node = pair.first;
            int weight = pair.second;
            dist[i][node] = weight;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            for (int j = 1; j <= n; j++) {
                if (j == k) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        AdjList[a].push_back(ii(b, c));
        AdjList[b].push_back(ii(a, c));
    }

    floydWarshall();

    for (int i = 0; i < q; i++) {
        cin >> a >> b;

        if (dist[a][b] == INF) cout << -1 << endl;
        else cout << dist[a][b] << endl;
    }

    return EXIT_SUCCESS;
}