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
        int sum=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            mini=min(mini,a);
            sum+=mini;
        }
        cout<<sum<<endl;
    }
    return 0;
}