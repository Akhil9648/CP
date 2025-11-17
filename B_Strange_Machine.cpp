#include <bits/stdc++.h>
using namespace std;

long long apply_cycle(long long x, const string &s) {
    for (char c : s) {
        if (x == 0) break;
        if (c == 'A') x -= 1;
        else x /= 2;
    }
    return x;
}

long long steps_to_zero(long long x, const string &s) {
    long long steps = 0;
    int n = s.size();
    while (x > 0) {
        for (int i = 0; i < n && x > 0; i++) {
            if (s[i] == 'A') x -= 1;
            else x /= 2;
            steps++;
        }
    }
    return steps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<long long> queries(q);
        for (auto &x : queries) cin >> x;

        for (auto x : queries) {
            cout << steps_to_zero(x, s) << "\n";
        }
    }
}
