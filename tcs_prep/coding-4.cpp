#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string s;
    getline(cin>>ws,s);
    stringstream ss(s);
    string curr;
    int cnt=0;
    vector<int>arr(n),dept(n);
    while(ss>>curr){
        if(cnt<n){
            arr[cnt]=stoi(curr);
        }
        else{
            dept[cnt-n]=stoi(curr);
        }
        cnt++;
    }
    vector<pair<int,int>>tr;
    for(int i=0;i<n;i++){
        tr.push_back({arr[i],dept[i]});
    }
    sort(tr.begin(),tr.end(),[](const auto &a,const auto &b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    });
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        int a=tr[i].first;
        int b=tr[i].second;
        int tp=pq.empty()?0:pq.top();
        if(tp>0 && tp<a){
            pq.pop();
            pq.push(b);
        }
        else{
            pq.push(b);
        }
    }
    cout<<pq.size();
}