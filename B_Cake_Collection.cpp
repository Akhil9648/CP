#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        long long a,b;
        cin>>a>>b;
        vector<long long>arr(a);
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        long long count=0;
        for(long long i=a-1;i>=0;i--){
            count+=arr[i]*b;
            b--;
            if(b==0) break;
        }
        cout<<count<<endl;
    }
    return 0;
}
