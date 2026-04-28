#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
int dp[MAXN + 1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                int a = j, b = i / j;
                dp[i] = min(dp[i], dp[a] + dp[b]);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int X;
        cin >> X;
        if (X == 1) {
    cout << 0 << '\n';
} else {
    cout << min(dp[X - 1], dp[X]) << '\n';
}
    }
}