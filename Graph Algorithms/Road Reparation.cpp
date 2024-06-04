#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>

using namespace std;

vector<int> id, sz;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if (p == q) return;
    if (sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
}

void DFS(vector<vector<int>>& G, vector<bool>& vis, int s){
    vis[s] = true;
    for (auto w : G[s]) if (!vis[w]){
        DFS(G, vis, w);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<iii> E;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<bool> vis(n);

    id.resize(n);
    sz.assign(n, 1);
    iota(id.begin(), id.end(), 0);

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        E.emplace_back(w, a, b);
    }

    DFS(G, vis, 0);
    for(int i = 0; i < n; i++){
        if (!vis[i]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    sort(E.begin(), E.end());
    ll res = 0;
    for(auto [w,a,b] : E){
        if (find(a) != find(b)){
            uni(a, b);
            res += w;
        }
    }

    cout << res << endl;

}