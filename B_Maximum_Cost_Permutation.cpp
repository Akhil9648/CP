#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n),pref(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            pref[i]=i+1;
        }
        int count=0,z=0;
        for(int i=0;i<n;i++){
            if(pref[i]!=arr[i] && arr[i]!=0){
                count++;
            }
            if(arr[i]==0){
                z++;
            }
        }
        if(z>1) count+=z;
        cout<<count<<endl;
    }
    return 0;
}
