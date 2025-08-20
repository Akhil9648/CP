#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>a(26,0);
        for(char c:s){
            a[c-'a']++;
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(a[i] >= 3){
                flag=1;
            }
            else if(a[i]==2 && (s[0]-'a'!=i || s.back()-'a'!=i)){
                flag=1;
            }
    }
    if(flag){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    }
    return 0;
}
