#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    bool suffix_upper = all_of(s.begin() + 1, s.end(), ::isupper);

    if (suffix_upper) {
        for (char &c : s) {
            c = isupper(c) ? tolower(c) : toupper(c);
        }
        cout << s;
    } else {
        cout << s;
    }
    
    return 0;
}