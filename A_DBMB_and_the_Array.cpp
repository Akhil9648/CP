#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum=0;
        for(int i=0;i<a;i++){
            int x;
            cin>>x;
            sum+=x;
        }
        int remaining=b-sum;
        if(sum>b || remaining%c!=0){
            cout<<"NO"<<endl;
            continue;
        }
        // else if(sum==b || remaining%c==0) cout<<"YES"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}