#include<bits/stdc++.h>
using namespace std;
int issubs(vector<int>& arr,int n){
    unordered_map<int,int>mp;
    int a=0;
    for(int k=0;k<n;k++){
        mp[arr[k]]++;
        a=max(a,mp[arr[k]]);
    }
    int sum=0;
    while(a){
        int b=0;
        for(auto it:mp){
            if(it.second>=a){
                b+=a;
            }
        }
        sum=max(sum,b);
        a--;
    }
    return sum;
}
void solve(vector<int>&nums,int i,int n,int maxi){
    if(i==n) return;
}
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
        int  maxi=issubs(arr,n);
        cout<<maxi<<endl;
    }
    return 0;
}
