#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int d=k;
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                d--;
            }
            else{
                if(d>0){
                    d=k;
                }
                else{
                    ans++;
                    i++;
                    d=k;
                    continue;
                }
            }
            if(d==0){
                ans++;
                d=k;
                i++;
            }

        }
            cout<<ans<<"\n";
    }
    return 0;
}
