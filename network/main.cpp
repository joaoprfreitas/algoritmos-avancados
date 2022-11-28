#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_NODES 101

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, s, t, c, res[MAX_NODES][MAX_NODES];

int edmondsKarp(vector<vii> &adjList) {
    int mf = 0;
    while (true) {
        queue<int> q;
        q.push(s);
        vii p(MAX_NODES, ii(-1, -1));
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;
            for (int j = 0; j < (int)adjList[u].size(); j++) {
                ii v = adjList[u][j];
                if (res[u][v.first] > 0 && p[v.first].first == -1) {
                    p[v.first] = ii(u, v.second);
                    q.push(v.first);
                }
            }
        }
        if (p[t].first == -1) break;
        int f = 1 << 30;
        for (int u = t; u != s; u = p[u].first) {
            f = min(f, res[p[u].first][u]);
        }
        for (int u = t; u != s; u = p[u].first) {
            res[p[u].first][u] -= f;
            res[u][p[u].first] += f;
        }
        mf += f;
    }
    return mf;
}

int main() {
    int i = 1;
    
    while (cin >> n) {
        if (n == 0) break;
        cin >> s >> t >> c;

        memset(res, 0, sizeof(res));
        vector<vii> adjList(MAX_NODES);

        for (int i = 0; i < c; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            res[u][v] += w;
            res[v][u] += w;

            adjList[u].push_back(ii(v, w));
            adjList[v].push_back(ii(u, w));
        }

        if (i != 1) cout << endl;

        cout << "Network " << i++ << endl;
        cout << "The bandwidth is " << edmondsKarp(adjList) << "." << endl;
    }

    return EXIT_SUCCESS;
}