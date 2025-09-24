#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        string s;
        cin>>n>>s;
        vector<int>arr(n,0);
        int a=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') a++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && a>0){
                count++;
                a--;
            }
            else a--;
        }
        cout<<count<<endl;  
    }
    return 0;
}
