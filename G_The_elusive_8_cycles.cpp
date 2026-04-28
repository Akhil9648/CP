#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (adj[i].size() >= 4) {
                root = i;
                break;
            }
        }

        if (root == -1) {
            cout << "NO\n";
            continue;
        }

        vector<int> neighbors = adj[root];
        vector<int> isNeighbor(n + 1, 0);
        for (int v : neighbors) isNeighbor[v] = 1;

        set<pair<int,int>> edges;

        for (int v : neighbors) {
            queue<int> q;
            vector<int> vis(n + 1, 0);

            q.push(v);
            vis[v] = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (nei == root) continue;

                    if (isNeighbor[nei] && nei != v) {
                        int a = min(v, nei);
                        int b = max(v, nei);
                        edges.insert({a, b});
                    }

                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push(nei);
                    }
                }
            }
        }

        if (edges.size() >= 2) cout << "YES\n";
        else cout << "NO\n";
    }
}