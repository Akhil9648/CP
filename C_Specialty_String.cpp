#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int no=0;
        stack<char>st;
        for(char c:s){
            if(st.empty() || st.top()!=c){\
                st.push(c);
            }
            else{
                if(st.top()==c) st.pop();
            }
        }
        if(st.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
