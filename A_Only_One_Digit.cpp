#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        int a=9;
        while(n){
            int d=n%10;
            n/=10;
            a=min(a,d);
        }
        cout<<a<<"\n";
    }
    return 0;
}
