#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a;
    cin >> a;
    vector<int> arr(a);
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    vector<int> max_pos(a);
    max_pos[a - 1] = a - 1;

    for (int i = a - 2; i >= 0; i--) {
        if (arr[i] >= arr[max_pos[i + 1]]) {
            max_pos[i] = i;
        } else {
            max_pos[i] = max_pos[i + 1];
        }
    }

    for (int i = 0; i < a; i++) {
        int target = max_pos[i];
        if (arr[i] < arr[target]) {
            reverse(arr.begin() + i, arr.begin() + target + 1);
            break;
        }
    }

    for (int i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}