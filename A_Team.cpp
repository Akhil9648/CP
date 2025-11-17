#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int count=0;
    while(t--)
    {
        int a=0;
        for(int i=0;i<3;i++){
            int x;
            cin>>x;
            a+=x;
        }
        if(a>=2){
            count++;
        }
    }
    cout<<count<<endl;
}
