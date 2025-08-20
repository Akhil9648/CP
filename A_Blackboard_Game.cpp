#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;;
        if(n%4==0){
            cout<<"Bob\n";
        }
        else{
            cout<<"Alice\n";
        }
    }
    return 0;
}
