#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if(t>n) {
        cout<<-1;
        return 0;
    }
    int tw=n/2;
    int o=0;
    if(n%2!=0) o++;
    while((tw+o)%t!=0){
        tw--;
        o+=2;
        if(tw*2+o>n){
            cout<<-1;
            return 0;
        }
    }
    cout<<tw+o;
    return 0;
}
