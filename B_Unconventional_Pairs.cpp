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
        sort(arr.begin(),arr.end());
        int maxi=0;
        for(int i=0;i<n;i+=2){
            int a=abs(arr[i]-arr[i+1]);
            maxi=max(a,maxi);
        }
        cout<<maxi<<endl;
    }
}
