#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while(k--){
    int cnt=0;
    int n,alice;
    cin>>n>>alice;
    int big=0,less=0;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>=alice){
            big++;
        }
        else{
            less++;
        }
    }
    int ans=1337;
    sort(arr.begin(),arr.end());
    if(less>=big){
        for(int i=n-1;i>=0;i--){
            if(arr[i]<alice){
                ans=arr[i];
                break;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(arr[i]>alice){
                ans=arr[i];
                break;
            }
        }
    }
    cout<<ans<<"\n";
}
    return 0;
}
