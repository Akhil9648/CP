#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        vector<int>arr(a);
        for(int i=0;i<a;i++)
        {
            cin>>arr[i];
        }
        int i=0;
        int k=0;
        while(i<a-1)
        {
            if(arr[i]>arr[i+1])
            {
                k=1;
                break;
            }
            i++;
        }
        if(k==1)
        {
            if(b==1)
            {
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
        else{
            cout<<"YES\n";
        }
    }
    return 0;
}
