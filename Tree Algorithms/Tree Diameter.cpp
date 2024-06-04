#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<vector<int>> G;
vector<bool> vis;

int max_dist = 0;
int longest_v = 0;

void dfs(int s, int par, int dist){
    if (dist > max_dist) {
        max_dist = dist;
        longest_v = s;
    }

    vis[s] = true;
    for(auto u : G[s]) if (!vis[u]){
        if (u == par) continue;
        dfs(u, s, dist+1);
    }
}

int main(){
    int n;
    cin >> n;
    G.resize(n);
    vis.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0, 0, 0);
    vis.assign(n, false);
    dfs(longest_v, longest_v, 0);

    cout << max_dist << endl;
}