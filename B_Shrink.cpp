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
            arr[i]=i+1;
        }
        int maxi=0;
        int flag=0;
        vector<int>ab=arr,ans=arr;
        int u=ab.size();
        while(!(is_sorted(ab.begin(),ab.end()))){
            next_permutation(ab.begin(),ab.end());
            ans=ab;
            int a=1;
            int count=0;
            while(a){
                a=0;
                int i=1;
                while(i<n-1){
                    if(ab[i]>ab[i-1] && ab[i]>ab[i+1]){
                        count++;
                        ab.erase(ab.begin()+i);
                        i=1;
                        u--;
                        a=true;
                    }
                    i++;
                }
                if(count>maxi){
                    arr=ans;
                    break;
                }
            }
            ab=arr;
    }
    for(int i:arr){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    return 0;
}
