#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        vector<int>arr(n+1,0),brr(m+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=0;i<m;i++){
            cin>>brr[i];
        }
        cout<<(n+m)<<endl;
    }
    return 0;
}
