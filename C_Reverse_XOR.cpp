#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bitset<32> binary_representation(n);
        string a = binary_representation.to_string();
        a.erase(0, a.find('1'));
        while (!a.empty() && a.back() == '0') a.pop_back();
        string b = a;
        reverse(b.begin(), b.end());
        if(a!=b){
            cout<<"NO"<<endl;
            continue;
        }
        if(a.size()%2==1 && a[a.size()/2]=='1'){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}
