#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,c;
    cin>>x>>c;
    int a=x*c/1000;
    x-=a;
    x-=x%1000;
    cout<<x;
    return 0;
}
