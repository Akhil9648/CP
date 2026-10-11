#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll S=720720;
vector<ll> divis;
vector<ll> result;
vector<ll> suffixSum;

bool dfs(int idx,int count,ll target) {
    if(count==0) return target==0;
    if(idx+count>(int)divis.size()) return false;
    if(target>suffixSum[idx]-suffixSum[idx+count]) return false;
    if(target<suffixSum[divis.size()-count]) return false;
    if(target>=divis[idx]){
        result.push_back(divis[idx]);
        if (dfs(idx + 1, count - 1, target - divis[idx])) return true;
        result.pop_back();
    }
    if(dfs(idx+1,count,target)) return true;
    return false;
}
void solve() {
    int n;
    if(!(cin>>n)) return;
    if(n==1) {
        cout<<1<<"\n";
        return;
    }
    if(n==2){
        cout<<-1<<"\n";
        return;
    }
    result.clear();
    if(dfs(0,n,S)) {
        for(int i=0;i<n;++i) {
            cout<<result[i]<<(i==n-1?"":" ");
        }
        cout<<"\n";
    } else {
        cout<<-1<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i=1;i*i<=S;++i){
        if (S%i==0){
            divis.push_back(i);
            if(i*i!=S) divis.push_back(S/i);
        }
    }
    sort(divis.rbegin(),divis.rend());
    auto it=find(divis.begin(),divis.end(),S);
    if(it!=divis.end()) divis.erase(it);
    suffixSum.assign(divis.size()+1,0);
    for (int i=(int)divis.size()-1;i>=0;--i){
        suffixSum[i]=suffixSum[i+1]+divis[i];
    }
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}