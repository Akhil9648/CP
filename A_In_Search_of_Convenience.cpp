#include <iostream>

using namespace std;

void solve() {
    long long x, y, R;
    cin >> x >> y >> R;
    cout << x - R << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int k;
    if (cin >> k) {
        while (k--) {
            solve();
        }
    }
    return 0;
}
