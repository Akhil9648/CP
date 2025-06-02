#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--)
    {
        int a;
        cin>>a;
        string s;
        cin>>s;
        int count=0;
        int k=s.size();
        for(int i=0;i<k;i++)
        {
            int j=0;
            while(j<k)
            {
                if(j==i)
                {
                    if(s[j]=='0')
                    {
                        count++;
                    }
                    j++;
                    continue;
                }
                if(s[j]=='1')
                {
                    count++;
                }
                j++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
