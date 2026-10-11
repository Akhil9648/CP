#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        vector<int>arr(3);
        int mini=n;
        for(int i=0;i<3;i++){
            cin>>arr[i];
            mini=min(mini,arr[i]);
        }
        cout<<n-mini<<endl;
    }
    return 0;
}