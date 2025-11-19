#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    while(k--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        char match=s[n-1];
        int ans=0;
        for(char c:s){
            if(c!=match) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
