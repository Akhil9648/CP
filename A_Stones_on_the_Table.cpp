#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=1;
    int count=0;
    while(i<n){
        if(s[i]==s[i-1]){
            count++;
        }
        i++;
    }
    cout<<count<<endl;
    return 0;
}
