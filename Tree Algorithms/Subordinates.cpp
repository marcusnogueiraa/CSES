#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<vector<int>> adj;
vector<int> subordinates;

int dfs(int s, int p){
    int sub_num = 0;
    for(auto v : adj[s]){
        if (v != p){
            sub_num += dfs(v, s) + 1;
        }Distance Queries
    }
    return subordinates[s] = sub_num;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    adj.resize(n);
    subordinates.resize(n);
    for(int i = 1; i < n; i++){
        int a; cin >> a; a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    dfs(0, -1);
    for(auto n : subordinates){
        cout << n << " ";
    }
    cout << endl;
}