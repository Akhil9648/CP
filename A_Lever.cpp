#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for (int  i = 0; i <n; i++)
        {
            cin>>a[i];
        }
        for (int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int count = 0,flag=0;
        while(1){
            if(flag){
            for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                count++;
                a[i]--;
                flag=1;
            }
            }
        }
             else{
                for(int i = 0; i < n; i++) {
                    if(b[i] > a[i]) {
                        count++;
                        b[i]--;
                        break;
                    }
                break;    
            }
        }
    }
    cout<< count << endl;
}
    return 0;
}