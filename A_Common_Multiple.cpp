#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        unordered_set<int> st;
        for(int i=0;i<a;i++)
        {
            int b;
            cin>>b;
            st.insert(b);
        }
        cout<<st.size()<<"\n";
    }
    return 0;
}
