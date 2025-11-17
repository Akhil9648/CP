#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int eve=0,odd=0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0) eve=1; else odd=1;
        }
        if(eve && odd){
            sort(arr.begin(),arr.end());
        }
        for(int i:arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
