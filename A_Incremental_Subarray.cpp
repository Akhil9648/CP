#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector<int>find(n);
        for(int i=0;i<n;i++){
            cin>>find[i];
        }
        vector<int>arr;
        for(int i=1;i<=m;i++){
            arr.push_back(i);
            vector<int>bfr; 
            for(int it:arr){
                bfr.push_back(it);
            }
            for(int it:bfr){
                arr.push_back(it);
            }
        }
        for(int i:arr){
            cout<<i<<" ";
        }
    }
    return 0;
}
