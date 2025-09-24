#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>dis(m);
        for(int i=0;i<m;i++){
            cin>>dis[i];
        }
        sort(arr.begin(),arr.end());
        sort(dis.rbegin(),dis.rend());
        int i=0,sum=0,j=0;
        for(int it:dis){
            for(;i<i+it-1 && i<n;i++){
                sum+=arr[i];
            }
            i++;
        }
        while(j<n){
            sum+=arr[j];
            j++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
