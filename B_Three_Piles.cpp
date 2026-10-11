#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<b){
            cout<<max(abs(a-b),abs((a+c)-b))<<endl;
            continue;
        }
        cout<<a+c-b<<endl;
    }
    return 0;
}