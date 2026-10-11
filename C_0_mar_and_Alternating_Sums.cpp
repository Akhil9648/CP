#include<bits/stdc++.h>
using namespace std;
int solve(int i,vector<int>& arr,int sum,int flag,int n){
    if(i>=n){
        if(sum==0) return 1;
        return 0;
    }
    int take=0;
    if(!flag){
        take=solve(i+1,arr,sum+arr[i],1,n);
    }
    else{
        take=solve(i+1,arr,sum-arr[i],0,n);
    }
    int notTake=solve(i+1,arr,sum,flag,n);
    return take+notTake;
}
int main(){
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int a=solve(0,arr,0,0,n);
        cout<<a<<endl;
    }
    return 0;
}