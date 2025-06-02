#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            if(i!=x)
            {
                arr.push_back(i);
            }
        }
        arr.push_back(x);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
