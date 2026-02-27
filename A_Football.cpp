#include<bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    unordered_map<string,int> mp;
    while(x--){
        string s;
        cin>>s;
        mp[s]++;
    }
    int maxi=0;
    string ans;
    for(auto it:mp){
        if(it.second>maxi){
            ans=it.first;
            maxi=it.second;
        }
    }
    cout<<ans;
    return 0;
}