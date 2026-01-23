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
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        a = arr.size();
        int curr=0,best=0;
        for(int i=0;i<a;i++){
            if(i==0 || arr[i]!=arr[i-1]+1){
                curr=0;
            }
            curr++;
            best=max(best,curr);
        }
            cout<<best<<endl;
    }
    return 0;
}