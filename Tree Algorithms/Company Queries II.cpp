#include <bits/stdc++.h>

using namespace std;

int l, timer = 0;
vector<int> tin, tout;
vector<vector<int>> G, up;

void dfs(int u, int p){
    tin[u] = ++timer;
    up[u][0] = p;

    for(int i = 1; i <= l; i++){
        up[u][i] = up[up[u][i-1]][i-1];
    }

    for(int to : G[u]){
        if (to != p){
            dfs(to, u);
        }
    }

    tout[u] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    else if (is_ancestor(v, u)) return v;

    for(int i = l; i >= 0; i--){
        if (!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }

    return up[u][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    l = ceil(log2(n));

    G.resize(n);
    tin.resize(n); tout.resize(n);
    up.assign(n, vector<int>(l+1));

    for(int i = 1; i <= n-1; i++){
        int a; cin >> a; a--; 
        G[i].push_back(a);
        G[a].push_back(i);
    }

    dfs(0, 0);
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b; a--; b--;
        cout << lca(a, b)+1 << endl;
    }
}