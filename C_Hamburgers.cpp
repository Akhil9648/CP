#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        string s;
        cin>>s;
        int b,s1,c;
        cin>>b>>s1>>c;
        int cb,cs,cc;
        cin>>cb>>cs>>cc;
        int totalc;
        cin>>totalc;
        int a=0,bb=0,cc1=0;
        for(char ch:s){
            if(ch=='B') a++;
            else if(ch=='S') bb++;
            else cc1++;
        }
        int count=0;
        while(b>=a && s1>=bb && c>=cc1){
            count++;
            b-=a;
            s1-=bb;
            c-=cc1;
        }
        int total=a*cb+bb*cs+cc1*cc;
        if(totalc>=total){
            count+=totalc/total;
        }
        cout<<count<<endl;
    }
    return 0;
}