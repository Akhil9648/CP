#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    while(k--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<char>st;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        cout<<st.size()/2<<endl;
    }
    return 0;
}