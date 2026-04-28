#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        for(int a=0;a<=n;a++){
            for(int b=0;b<=n;b++){
                int sum=a*b+a+b+1;
                if(sum==sqrt(sum)*sqrt(sum)) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
