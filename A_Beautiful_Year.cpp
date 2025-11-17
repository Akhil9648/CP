#include<bits/stdc++.h>
using namespace std;
int main(){
    int y;
    cin>>y;
    while(1){
        y++;
        string s=to_string(y);
        unordered_set<char>st(s.begin(),s.end());
        if(st.size()==4) break;
    }
    cout<<y;
}
