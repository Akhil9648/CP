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
        vector<int>arr(n),res(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]%6==0){
                res[j]=arr[i];
                arr[i]=-1;
                j++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]%3==0){
                res[j]=arr[i];
                arr[i]=-1;
                j++;
            }
        }
        int k=n-1;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                res[k]=arr[i];
                arr[i]=-1;
                k--;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                res[j]=arr[i];
                j++;
            }
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}