#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        string s;
        cin>>n>>k>>s;
        stack<int>st;
        vector<int>ans(n,0),rem;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                if(!st.empty()){
                    rem.push_back(st.top());
                    st.pop();
                }
            }
        }
        int size=min(k,(int)rem.size());
        for(int i=0;i<size;i++){
            ans[rem[i]]=1;
        }
        for(auto it:ans) cout<<it;
        cout<<endl;
    }
    return 0;
}