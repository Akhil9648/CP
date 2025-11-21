#include <bits/stdc++.h>
using namespace std;
int main() {
        int a,b,c;
        cin>>a>>b>>c;
        long long u=(a+c-1)/c;
        long long v=(b+c-1)/c;
        cout<<u*v<<endl;
    return 0;
}
