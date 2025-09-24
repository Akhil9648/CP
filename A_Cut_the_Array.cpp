#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>arr(n),pref(n+1,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            pref[i+1]=pref[i]+arr[i];
        }
        bool flag=false;
        for(int l=1;l<=n && !flag;l++){
            for(int r=l+1;r<=n;r++){
                int s1=pref[l]%3;
                int s2=(pref[r]-pref[l])%3;
                int s3=(pref[n]-pref[r])%3;
                if((s1==s2 && s2==s3)|| (s1!=s2 && s2!=s3 && s1!=s3)){
                    cout<<l<<" "<<r<<endl;
                    flag=true;
                    break;
                }
            }
        }
        if(!flag) cout<<"0 0"<<endl;
    }
    return 0;
}
