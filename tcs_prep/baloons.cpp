#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<char>arr(n);
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]]++;
    }
    for(auto it:arr){
        if(mp[it]%2==1){
            cout<<it<<endl;
            return 0;
        }
    }
    return 0;
}