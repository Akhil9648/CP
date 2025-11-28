#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    string a="hello";
    int i=0;
    for(char c:s){
        if(c==a[i]){
            i++;
        }
    }
    if(i==5) cout<<"YES";
    else cout<<"NO";
    return 0;
}
