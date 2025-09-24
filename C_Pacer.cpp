#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        long long n,m;
        cin>>n>>m;
        vector<pair<long long,int>>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        long long ans=0,prev=0;
        int curr=0;
        for(int i=0;i<n;i++){
            long long a=arr[i].first;
            int b=arr[i].second;
            long long val=a-prev;
            ans+=val;
            int fin=curr^(val%2);
            if(fin!=b){
                ans--;
                fin=b;
            }
            curr=fin;
            prev=a;
        }
        ans+=m-prev;
        cout<<ans<<endl;
    }
    return 0;
}
