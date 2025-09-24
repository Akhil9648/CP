#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        c-=a;
        d-=b;
        int u=0,v=0;
        if(a<b){
            u=b-2*a;
        }
        else{
            u=a-2*b;
        }
        if(c<d){
            v=d-2*c;
        }
        else{
            v=c-2*d;
        }
        if(u>2 || v>2){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}
