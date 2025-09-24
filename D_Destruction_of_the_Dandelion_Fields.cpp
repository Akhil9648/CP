#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        int odd=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==1) odd++;
        }
        if(odd==0){
            cout<<"0"<<endl;
            continue;
        }
        long long ans=0;
        for(int i:arr){
            ans+=i;
        }
        int flag=odd/2;
        sort(arr.begin(),arr.end());
        for(int i:arr){
            if(flag==0) break;
            if(i%2==1){
                ans-=i;
                flag--; 
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
