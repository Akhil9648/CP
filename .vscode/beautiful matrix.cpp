#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> mat(5,vector<int>(5,0));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}