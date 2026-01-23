#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        vector<int>arr(a);
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        int max_val = *max_element(arr.begin(), arr.end());
        cout<<max_val*a<<endl;
    }
    return 0;
}