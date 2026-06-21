#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n),ans(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<int>st,s2;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>arr[i]){
            s2.push(st.top());
            st.pop();
        }
        while(!s2.empty() && s2.top()<arr[i]){
            st.push(s2.top());
            s2.pop();
        }
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.size();
        st.push(arr[i]);
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}