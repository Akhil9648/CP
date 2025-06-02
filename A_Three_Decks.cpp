#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((a+b+c)%3!=0){
            cout<<"NO\n";
        }
        else{
            int s=(a+b+c)/3;
            if(s<a || s<b){
                cout<<"NO\n";
            }   
            else{
                cout<<"YES\n";
            }
        }
    }
    return 0;
}
