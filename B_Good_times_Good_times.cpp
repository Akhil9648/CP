#include <bits/stdc++.h>
using namespace std;

bool valid(long long n) {
    int mask = 0;
    while (n > 0) {
        mask |= (1 << (n % 10));
        n /= 10;
    }
    return __builtin_popcount(mask) <= 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<int> st;

    for (int d1 = 0; d1 <= 9; d1++) {
        for (int d2 = d1; d2 <= 9; d2++) {

            vector<long long> q;

            if (d1 > 0)
                q.push_back(d1);

            if (d2 > 0 && d2 != d1)
                q.push_back(d2);

            for (size_t i = 0; i < q.size(); i++) {
                long long num = q[i];

                if (num >= 2 && num <= 100000000)
                    st.insert((int)num);

                long long nxt = num * 10 + d1;
                if (nxt <= 100000000)
                    q.push_back(nxt);

                if (d1 != d2) {
                    nxt = num * 10 + d2;
                    if (nxt <= 100000000)
                        q.push_back(nxt);
                }
            }
        }
    }

    vector<int> arr(st.begin(), st.end());

    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        bool found = false;

        for (int y : arr) {
            if (valid(1LL * x * y)) {
                cout << y << '\n';
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << '\n';
    }

    return 0;
}