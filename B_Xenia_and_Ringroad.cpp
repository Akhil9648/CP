#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n,m;
        cin>>n>>m;
        vector<int>arr(m);
        for(int i=0;i<m;i++){
            cin>>arr[i];
        }
        long long time=arr[0]-1;
        for(int i=1;i<m;i++){
            if(arr[i]>=arr[i-1]){
                time+=(arr[i]-arr[i-1]);
            }
            else{
                time+=(n-arr[i-1])+arr[i];
            }
    }
    cout<<time<<endl;
    return 0;
}