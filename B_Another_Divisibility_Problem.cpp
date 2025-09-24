#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        long long x;
        cin>>x;
        long long y=-1;
        for(int i=1;i<=9;i++){
            long long j=pow(10,i)-1-x;
            if(j>=pow(10,i-1) && j<pow(10,i)){
                y=j;
                break;
            }
        }
        cout<<y<<endl;  
    }
    return 0;
}
