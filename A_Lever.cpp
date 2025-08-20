#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for (int  i = 0; i <n; i++)
        {
            cin>>a[i];
        }
        for (int i=;i<n;i++)
        {
            cin>>b[i];
        }
        int count = 0,flag=0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                count++;
                a[i]--;
            }
            if(a[i] < b[i]) {
                count++;
                b[i]--;
                break;
            }
        }
        
    }
    
    return 0;
}