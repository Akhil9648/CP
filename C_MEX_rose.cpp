#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        unordered_set<int>st;
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==k) cnt++;
            if(arr[i]<k){
                st.insert(arr[i]);
            }
        }
        int miss=0;
        for(int i=0;i<k;i++){
            if(!st.count(i)) miss++;
        }
        cout<<max(miss,cnt)<<endl;
    }
}
