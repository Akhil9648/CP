#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        int m=0,z=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==-1){
                m++;
            }
            if(arr[i]==0){
                z++;
            }
        }
        int a=0;
        if(m%2==1){
            a+=2;
        }
        a+=z;
        cout<<a<<endl;
    }
}
