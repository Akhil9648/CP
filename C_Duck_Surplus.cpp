#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        vector<long long>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long maxi=arr[0];
        // cout<<arr[0]<<" ";
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                arr[i]+=arr[i+1];
                swap(arr[i],arr[i+1]);
            }
            // cout<<arr[i+1]<<" ";
            maxi=max(maxi,arr[i+1]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}