#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int flag=0;
    while(n>1){
        if(flag){
            cout<<"I love that ";
            flag=0;
        }
        else{
            cout<<"I hate that ";
            flag=1;
        }
        n--;
    }
    if(flag){
            cout<<"I love it";
            flag=0;
        }
        else{
            cout<<"I hate it";
        }
    return 0;
}
