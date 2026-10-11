#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main() {
    int a, b;
    cin>>a>>b;
    cin.ignore(); 
    string s;
    getline(cin >> ws, s);
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    stringstream ss(s);
    vector<vector<int>> mat(a, vector<int>(b));
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
        ss>>mat[i][j];
        }
    }
    int c;
    cin>>c;
    vector<vector<int>>swaps(c,vector<int>(4));
    for(int i=0;i<c;i++){
        for(int j=0;j<4;j++){
            cin>>swaps[i][j];
        }
    }
    for(int i=0;i<c;i++){
        int u=swaps[i][0];
        int v=swaps[i][1];
        int x=swaps[i][2];
        int y=swaps[i][3];
        swap(mat[u][v],mat[x][y]);
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
