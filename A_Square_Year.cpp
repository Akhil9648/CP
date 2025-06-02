#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int t;
        cin>>t;
        int a=sqrt(t);
        if((a*a)!=t){
            cout<<"-1\n";
            continue;
        }
        if(a==0){
            cout<<"0 0\n";
            continue;
        }
        cout<<a-1<<" "<<1<<"\n";
    }
    return 0;
}
