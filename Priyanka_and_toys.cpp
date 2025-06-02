#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>arr){
    int n=arr.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]=i;
    }
    sort(arr.begin(),arr.end());
    int min=arr[0];
    int con=1;
    for(int i=0;i<n;i++){
        if(arr[i]>(min+4)){
            con++;
            min=arr[i];
        }
        cout<<arr[i]<<" in container "<<con<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr);
    return 0;
}
