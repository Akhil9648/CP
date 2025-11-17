#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        auto feasible = [&](long long D)->bool {
            // Build merged forbidden intervals F over [0, x]
            vector<pair<long long,long long>> segs;
            segs.reserve(n);
            for (long long ai : a) {
                long long L = max(0LL, ai - D);
                long long R = min(x, ai + D);
                segs.emplace_back(L, R);
            }
            sort(segs.begin(), segs.end());
            vector<pair<long long,long long>> forb;
            for (auto [L, R] : segs) {
                if (forb.empty() || L > forb.back().second + 1) {
                    forb.emplace_back(L, R);
                } else {
                    forb.back().second = max(forb.back().second, R);
                }
            }
            // Count allowed integer points in gaps of forbidden union within [0,x]
            long long need = k;
            long long prev = -1; // end of previous forbidden
            for (auto [L, R] : forb) {
                long long gapL = max(prev + 1, 0LL);
                long long gapR = min(L - 1, x);
                if (gapL <= gapR) {
                    long long cnt = gapR - gapL + 1;
                    need -= cnt;
                    if (need <= 0) return true;
                }
                prev = R;
            }
            // Tail gap after last forbidden
            long long gapL = max(prev + 1, 0LL);
            long long gapR = x;
            if (gapL <= gapR) {
                long long cnt = gapR - gapL + 1;
                need -= cnt;
            }
            return need <= 0;
        };

        // Binary search the maximum D in [0, x]
        long long lo = 0, hi = x, bestD = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (feasible(mid)) {
                bestD = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Reconstruct k positions using bestD
        auto build_positions = [&](long long D)->vector<long long> {
            vector<pair<long long,long long>> segs;
            segs.reserve(n);
            for (long long ai : a) {
                long long L = max(0LL, ai - D);
                long long R = min(x, ai + D);
                segs.emplace_back(L, R);
            }
            sort(segs.begin(), segs.end());
            vector<pair<long long,long long>> forb;
            for (auto [L, R] : segs) {
                if (forb.empty() || L > forb.back().second + 1) {
                    forb.emplace_back(L, R);
                } else {
                    forb.back().second = max(forb.back().second, R);
                }
            }
            vector<long long> res;
            res.reserve(k);
            long long prev = -1;
            auto emit_gap = [&](long long L, long long R) {
                for (long long p = L; p <= R && (int)res.size() < k; ++p) {
                    res.push_back(p);
                }
            };
            for (auto [L, R] : forb) {
                long long gapL = max(prev + 1, 0LL);
                long long gapR = min(L - 1, x);
                if (gapL <= gapR) emit_gap(gapL, gapR);
                if ((int)res.size() == k) break;
                prev = R;
            }
            if ((int)res.size() < k) {
                long long gapL = max(prev + 1, 0LL);
                long long gapR = x;
                if (gapL <= gapR) emit_gap(gapL, gapR);
            }
            // If still short (shouldn't happen due to k-1<=x), fill anywhere distinct
            for (long long p = 0; (int)res.size() < k && p <= x; ++p) res.push_back(p);
            return res;
        };

        vector<long long> ans = build_positions(bestD);
        for (int i = 0; i < k; ++i) {
            cout << ans[i] << (i + 1 == k ? '\n' : ' ');
        }
    }
    return 0;
}
