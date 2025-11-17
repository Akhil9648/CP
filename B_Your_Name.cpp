#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s,k;
        cin>>s>>k;
        sort(s.begin(),s.end());
        sort(k.begin(),k.end());
        if(s==k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
