#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>edges(vector<int>(n,vector<int>(2)));
    cout<<"Enter the adjacency matrix of the graph:"<<endl;
    for(int i=0;i<n;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int>q;
    q.push(0);
    vector<int>vis(n,0);
    vis[0]=1;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout<<curr<<" ";
        for(int i:adj[curr]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
            }
        }
    }
    return 0;
}