#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n>2){
            int a=n/3;
            ans+=a;
            n-=2*a;
        }
        cout<<ans<<endl;
    }
}
