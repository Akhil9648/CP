#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b,c;
    cin>>a>>b>>c;
    unordered_map<char,int> mp;
    for(int i=0;i<a.size();i++){
        mp[a[i]]++;
    }
    for(int i=0;i<b.size();i++){
        mp[b[i]]++;
    }
    unordered_map<char,int> mp2;
    for(int i=0;i<c.size();i++){
        mp2[c[i]]++;
    }
    for(auto it:mp2){
        if(mp[it.first]!=it.second){
            cout<<"NO"<<endl;
            return 0;
        }
    }
     for(auto &it : mp){
        if(mp2[it.first] != it.second){
            cout << "NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
