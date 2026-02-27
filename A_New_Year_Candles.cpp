#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;
    int cnt=a;
    while(a>=b){
        int c=a/b;
        a%=b;
        cnt+=c;
        // a+=c;
    }
    // cnt+=a;
    cout<<cnt;
    return 0;
}