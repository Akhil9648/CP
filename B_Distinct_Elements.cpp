#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<long long> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];

        vector<int> a(n+1);
        long long prev = 0, distinct = 0;
        int nxt = 1, anchor = 0; // anchor stores some introduced value to reuse
        for(int i=1;i<=n;i++){
            long long d = b[i] - prev; prev = b[i];
            if(d == distinct + 1){
                a[i] = nxt++;
                distinct++;
                if(anchor == 0) anchor = a[i];
            }else{ // d == distinct
                // reuse an existing value (anchor is guaranteed set once distinct>0)
                a[i] = anchor;
            }
        }
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}
