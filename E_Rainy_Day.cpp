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
        vector<int> h(n + 1);
        for (int i = 1; i <= n; i++) cin >> h[i];
        for (int s = 1; s <= n + 1; s++) {
            bool bad = false;
            for (int i = s; i <= n; i += s) {
                if ((i / s) % h[i] == 0) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                cout << s << '\n';
                break;
            }
        }
    }
    return 0;
}