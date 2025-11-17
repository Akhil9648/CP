#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    unordered_set<char>st;
    for(auto c:s){
        if((c>='a' && c<='z') || (c>='A' && c<='Z')){
            st.insert(c);
        }
    }
    cout<<st.size();
    return 0;
}
