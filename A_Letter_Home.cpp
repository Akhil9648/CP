#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int p,s;
        cin>>p>>s;
        vector<int>a(p);
        for(int i=0;i<p;i++)
        {
            cin>>a[i];
        }
        int ans=min(abs(s-a[0]),abs(s-a.back()))+a.back()-a[0];
        cout<<ans<<"\n";
    }
    return 0;
}
