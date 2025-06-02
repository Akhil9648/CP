#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        vector<int>nums(n,0);
        int a=0;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(nums[i]==0){
                a++;
            }
        }
        int flag=0;
        for(int i=0;i<n-1;i++){
            if((nums[i]==0) && (nums[i+1]==0)  || a==0){
                cout<<"YES\n";
                flag=1;
                break;
            }
        }
        if(!flag) cout<<"NO\n";
    }
    return 0;
}
\