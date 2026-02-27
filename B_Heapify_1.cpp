#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1), ans;
        for (int i = 1; i <= n; i++) cin >> a[i];

        ans = a;
        sort(ans.begin() + 1, ans.end());
        vector<int> vis(n + 1, 0);
        bool ok = true;

        for (int i = 1; i <= n && ok; i++) {
            if (vis[i]) continue;

            vector<int> idx;
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty()) {
                int u = q.front(); q.pop();
                idx.push_back(u);

                if (2 * u <= n && !vis[2 * u]) {
                    vis[2 * u] = 1;
                    q.push(2 * u);
                }
                if (u % 2 == 0 && !vis[u / 2]) {
                    vis[u / 2] = 1;
                    q.push(u / 2);
                }
            }

            vector<int> cur, target;
            for (int id : idx) {
                cur.push_back(a[id]);
                target.push_back(ans[id]);
            }

            sort(cur.begin(), cur.end());
            sort(target.begin(), target.end());

            if (cur != target) ok = false;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
