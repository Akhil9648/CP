#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll>divisors({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53});
        for(ll d:divisors){
        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]%d){
                flag=1;
                break;
            }
        }
            if(flag==1){
                cout<<d<<endl;
                break;
            }
        }
    }
}
