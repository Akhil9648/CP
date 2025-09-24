#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int maxi=0;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            maxi=max(maxi,arr[i]);
        }
        int l=0,r=n-1;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(arr[l]==i) l++;
            else if(arr[r]==i) r--;
            else{
                flag=1;
                cout<<"NO\n";
                break;
            }
        }
        if(!flag) cout<<"YES\n";
    }
    return 0;
}
