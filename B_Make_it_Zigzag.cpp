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
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        for(int i=1;i<n-1;i+=2){
            if(arr[i]==arr[i-1]) count++;
            if(arr[i]<=arr[i+1]){
                int a=0;
                int b=*max_element(arr.begin(),arr.begin()+i);
                if(b>arr[i+1]){
                    continue;
                }
                else {
                    a+=(arr[i+1]-b+1);
                }
                a=min(a,(arr[i+1]-arr[i]));
                count+=a;
            }
        }
        cout<<count<<endl;
    }
}
