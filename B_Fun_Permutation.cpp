#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int>solve(int i,vector<int>&arr,int n,vector<int>&curr){
    if(i==n){
        for(int j=0;j<n-1;j++){
            if(gcd((arr[j]+curr[j]),(arr[j+1]+curr[j+1]))<3){
                return {};
            }
        }
        return arr;
    }
    for(int j=i;j<n;j++){
        swap(arr[i],arr[j]);
        vector<int>ans=solve(i+1,arr,n,curr);
        if(!ans.empty()) return ans;
        swap(arr[i],arr[j]);
    }
    return {};
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> curr=arr;
        vector<int> temp=solve(0,arr,n,curr);
        for(auto x:temp) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
