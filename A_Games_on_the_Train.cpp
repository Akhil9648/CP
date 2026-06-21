#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
        cout<<maxi-mini+1;
        cout<<endl;
    }
    return 0;
}