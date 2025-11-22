#include <bits/stdc++.h>
using namespace std;
int main() {
        int n;
        cin>>n;
        vector<vector<int>>arr(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        int a=0;
        for(int j=0;j<3;j++){
        for(int i=0;i<n;i++){
            a+=arr[i][j];
        }
        if(a!=0){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
