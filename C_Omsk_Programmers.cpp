#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a,b,k;
        cin>>a>>b>>k;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(a>b) swap(a,b);
        int ans=b-a;
        int cnt=0;
        int bb=b;
        while(bb>a && bb>0){
            bb/=k;
            cnt++;
        }
        if(bb<a){
            ans=min(ans,cnt+(a-bb));
            int aa=a;
            int da=0;
            while(aa>bb && aa>0){
                aa/=k;
                da++;
            }
            ans=min(ans,cnt+da+(bb-aa));
        }
        else{
            ans=min(ans,cnt+(bb-a));
        }
        cout<<ans<<endl;
    }
    return 0;
}