#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        sort(nums.begin(),nums.end());
        if((nums[0]+nums[n-1])%2==0){
            cout<<"0\n";
            continue;  
        }
        int a=0;
        for(int i=0;i<n;i++){
            if((nums[i]+nums[n-1])%2==0){
                a=i;
                break;
            }
        }
        int b=0;
        for(int i=n-1;i>=0;i--){
            if((nums[i]+nums[0])%2==0){
                b=n-1-i;
                break;
            }
        }
        cout<<min(a,b)<<"\n";
    }
    return 0;
}
