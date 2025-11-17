#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        // Basic feasibility: cannot decrease any temperature
        bool impossible = false;
        for (int i = 0; i < n; ++i) {
            if (A[i] > B[i]) { impossible = true; break; }
        }
        if (impossible) {
            cout << "Case #" << t << ": -1\n";
            continue;
        }

        // Quick necessary condition: every distinct B value must exist somewhere in initial A
        // (if a target value v never appears initially in A, you can never create v).
        {
            unordered_set<int> setA(A.begin(), A.end());
            bool ok = true;
            for (int i = 0; i < n; ++i) if (!setA.count(B[i])) { ok = false; break; }
            if (!ok) {
                cout << "Case #" << t << ": -1\n";
                continue;
            }
        }

        // If already equal
        if (A == B) {
            cout << "Case #" << t << ": 0\n";
            continue;
        }

        // Group indices needing each target
        map<int, vector<int>> need; // ascending order by key
        for (int i = 0; i < n; ++i) {
            if (A[i] != B[i]) need[B[i]].push_back(i);
        }

        vector<pair<int,int>> ops;

        // Process targets in ascending order (important)
        for (auto &p : need) {
            int target = p.first;
            vector<int> &indices = p.second;

            // Find a heater index with A[idx] == target
            int heater = -1;
            for (int i = 0; i < n; ++i) {
                if (A[i] == target) { heater = i; break; }
            }
            if (heater == -1) { // no heater available for this target
                impossible = true;
                break;
            }

            // Use that heater to heat every index that needs this target
            for (int idx : indices) {
                if (A[idx] < target) {
                    // perform operation: heater -> idx
                    ops.emplace_back(heater + 1, idx + 1); // 1-based
                    A[idx] = target;
                }
            }
        }

        if (impossible) {
            cout << "Case #" << t << ": -1\n";
            continue;
        }

        // Final verification
        if (A != B) {
            cout << "Case #" << t << ": -1\n";
            continue;
        }

        cout << "Case #" << t << ": " << ops.size() << "\n";
        for (auto &op : ops) cout << op.first << " " << op.second << "\n";
    }

    return 0;
}