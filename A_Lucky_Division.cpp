#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int flag=0;
    int lucky_numbers[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
    for(int i:lucky_numbers){
        if(n%i==0){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
