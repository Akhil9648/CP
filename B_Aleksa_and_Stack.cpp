#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        long long n;
        cin>>n;
        long long k=3;
        while(n--){
            cout<<k<<" ";
            k+=2;
        }
        cout<<endl;
    }
    return 0;
}
