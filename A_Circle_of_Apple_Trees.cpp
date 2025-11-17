#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int cnt=0;
        int a=0;
        for(int i:arr){
            if(i>a){
                cnt++;
                a=i;
            }
        }
        cout<<cnt<<endl;
    }
}
