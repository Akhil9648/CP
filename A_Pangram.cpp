#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    vector<int>check(26,0);
    for(int i=0;i<s.size();i++){
        check[s[i]-'a']++;
    }
    int flag=1;
    for(int i=0;i<26;i++){
        if(check[i]==0){
            flag=0;
            cout<<"NO"<<endl;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    return 0;
}
