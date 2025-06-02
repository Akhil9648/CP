#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n,k;
        string s;
        cin>>n>>k>>s;
        int zero=count(s.begin(),s.end(),'0');
        int one=n-zero;
        int m=n/2;
        int r=m-k;
        if((zero<r) || (one<r)){
            cout<<"NO\n";
        }
        else if((zero-r)%2!=0 || (one-r)%2!=0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
