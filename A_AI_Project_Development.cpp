#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        int a=n,cntw=0,cnta=0;
        while(a>0){
            a-=x;
            a-=y;
            cntw++;
        }
        a=n;
        while(a>0){
            a-=x;
            if(z==0) a-=(10*y);
            else z--;
            cnta++;
        }
        cout<<min(cntw,cnta)<<endl;
    }
    return 0;
}