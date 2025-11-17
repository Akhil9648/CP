#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    unordered_set<int>st;
    int i=2;
    while(i--){
        int p;
        cin>>p;
        while(p--){
            int a;
            cin>>a;
            st.insert(a);
        }
    }
    if(st.size()==n){
        cout<<"I become the guy."<<endl;
    }
    else{
        cout<<"Oh, my keyboard!"<<endl;
    }
    return 0;
}
