#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        int p,q;
        string a,b,c;
        cin>>p>>a>>q>>b>>c;
        for(int i=0;i<q;i++){
            if(c[i]=='V'){
                a.insert(0,1,b[i]);
            }
            else if(c[i]=='D'){
                a.push_back(b[i]);
            }
        }
        cout<<a<<"\n";
    }
    return 0;
}
