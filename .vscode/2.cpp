#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int n1=n;
    int d=n1%10;
    int t=9-d;
    int count=0;
    if(t<d)
    {
        do
        {
            count++;   
        }while (n1/=10);
        n1=n;
        int b=1;
        while(count--)
        {
            int rem=pow(10,b);
            int a=n1%rem;
            if(a==d)
            {
                n1-=(b*pow(10,b));
                n1+=(t*pow(10,b));
            }
            b++;

        }
    }
    cout<<n1;
     return 0;
}