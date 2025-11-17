#include <bits/stdc++.h>
using namespace std;
int main() {
    int cnt=0;
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    for(int i=0;i<n;i++){
        unordered_set<int>st;
        st.insert(arr[i].first);
        st.insert(arr[i].second);
        for(int j=0;j<n;j++){
            if(j==i) continue;
            if(st.find(arr[j].first)!=st.end()) cnt++;
            if(st.find(arr[j].second)!=st.end()) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
