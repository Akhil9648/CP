#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int a;
        cin>>a;
        vector<int>arr(a);
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        int mini=arr[0],maxi=arr[0];
        int count=1;
        for(int i=1;i<a;i++){
            if(arr[i]<mini){
                mini=arr[i];
                count++;
            }
            else if(arr[i]>maxi){
                maxi=arr[i];
                count++;
            }
        }
        cout<<count-1<<endl;
    return 0;
}