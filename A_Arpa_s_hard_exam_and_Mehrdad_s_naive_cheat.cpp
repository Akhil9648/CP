#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;
    if (n == 0) {
        cout << 1;
        return 0;
    }
    int cycle[4] = {6, 8, 4, 2};
    cout << cycle[n % 4];
}
