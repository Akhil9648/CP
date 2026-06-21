#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int cnt=0;
        for(auto it:s){
            if(it=='1') cnt++;
        }
        int flag=1;
        if(cnt%2==1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<=n-k;i++){
            if(s[i]=='1'){
                if(i+k<n){
                    s[i]='0';
                    if(s[i+k]=='0') s[i+k]='1';
                    else s[i+k]='0';
                }
                else{
                    flag=0;
                    break;
                }
            }
        }
        for(auto it:s){
            if(it=='1'){
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}