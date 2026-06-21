#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,j,m,p;
    cin>>n>>k>>j>>m>>p;
    int ban=m/k;
    if(m%k) ban++;
    int pean=p/j;
    if(p%j) pean++;
    int mon=max(ban,pean);
    cout<<n-mon<<endl;
    return 0;
}