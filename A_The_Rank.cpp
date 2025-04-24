#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int n=t;
    vector<int>sum(n);
    for(int i=0;i<t;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        sum[i]=(a+b+c+d);
    }
    int a=sum[0];
    sort(begin(sum),end(sum),greater<int>());
    for(int i=0;i<n;i++)
    {
        if(sum[i]==a)
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}