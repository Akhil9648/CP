#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        int a;
        cin>>n>>a;
        vector<int>arr(n,0);
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            if(arr[i]==a){
                cout<<"YES\n";
                flag=1;
                break;
            }
        }
            if(!flag){
                cout<<"NO\n";
            }
    }
    return 0;
}
