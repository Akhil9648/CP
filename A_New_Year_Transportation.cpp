#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
        int a=0;
        while(a<k-1){
            a+=arr[a];
        }
    if(a==k-1){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}