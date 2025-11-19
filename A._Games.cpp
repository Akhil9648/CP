#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> team(n);
    for(int i = 0; i < n; i++) {
        cin >> team[i].first >> team[i].second;  // home, away
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(team[i].first == team[j].second) cnt++;
        }
    }

    cout << cnt;
    return 0;
}
