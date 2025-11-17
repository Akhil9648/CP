#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    int count=0;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(b-a>=2){
            count++;
        }
    }
    cout<<count<<endl;
}
