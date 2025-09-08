#include<bits/stdc++.h>
using namespace std;
int main(){
    int k;
    cin>>k;
    while(k--)
    {
        long long num;
        cin>>num;
        vector<int>ans;
        for(int i=1;i<log10(num)+1;i++){
            int a=num/pow(10,i);
            if(a*pow(10,i)+a==num){
                ans.push_back(a);
            }
        }
        for(int i: ans){
            cout<<i<<" ";
        }
        if(ans.empty()){
            cout<<"0";
        }
        cout<<"\n";
    }
    return 0;
}
