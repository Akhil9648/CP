#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int flag=0;
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int x=-1;
        for(int i=0;i<n;i++)
        {
            if(b[i]!=-1)
            {
                int curr_x=a[i]+b[i];
                if(x==-1) x=curr_x;
                else if(x!=curr_x)
                {
                    cout<<"0\n";
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            continue;
        }
        int valid_count=0;
        if(x==-1)
        {
            int min_a=*min_element(a.begin(),a.end());
            int max_a=*max_element(a.begin(),a.end());
            if(max_a>min_a+k) cout<<"0\n";
            else
            {
                valid_count=(min_a+k)-max_a+1;
                cout<<valid_count<<"\n";
            }
        }
        else
        {
            bool valid=true;
            for(int i=0;i<n;i++)
            {
                if(b[i]==-1)
                {
                    int bi=x-a[i];
                    if(bi<0||bi>k)
                    {
                        valid=false;
                        break;
                    }
                }
            }
            if(valid){ 
                valid_count=1;
            }
            cout<<valid_count<<"\n";
        }
    }
    return 0;
}