#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n+1, vector<int>(n+1));
        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j <=n; ++j) {
                cin >> grid[i][j];
            }
        }
        int total = 2 * n;
        vector<int> ans(total + 2, 0); // p[1..2n]
        vector<bool> filled(total + 2, false);
        for (int i = 1; i <=n; ++i) {
            for (int j = 1; j <=n; ++j) {
                int pos = i + j;
                ans[pos] = grid[i][j];
                filled[pos] = true;
            }
        }
        unordered_set<int> st;
        for (int i = 2; i <= total; ++i) {
            if (filled[i]) {
                st.insert(ans[i]);
            }
        }
        for (int val = 1; val <= total; ++val) {
            if (st.find(val) == st.end()) {
                ans[1] = val;
                break;
            }
        }
        for (int i = 1; i <= total; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}