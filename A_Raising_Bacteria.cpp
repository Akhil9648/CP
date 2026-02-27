#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int ans = 0;
    while (x > 0) {
        // If x is odd, the last bit is 1, so we need to add a bacterium
        if (x % 2 == 1) {
            ans++;
        }
        // Shift right (divide by 2) to check the next bit
        x /= 2;
    }

    cout << ans << endl;

    return 0;
}