#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin>>k;
    while(k--){
        stack<int>st;
        vector<int>arr;
        int n;
        string s;
        cin>>n>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='1') st.push(i+1);
            else if(s[i]=='2'){
                if(!st.empty()){
                    st.pop();
                    arr.push_back(i+1);
                }
            }
        }
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
