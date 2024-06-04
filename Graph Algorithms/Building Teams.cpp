#include <bits/stdc++.h>
 
#define endl '\n'
 
using namespace std;
 
int n, m;
vector<vector<int>> g;
vector<int> side;
 
bool isbipartite(){
    bool is_bipartite = true;
    queue<int> q;
    for(int st = 0; st < n; st++){
      if (side[st] == -1){
        q.push(st);
        side[st] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int u : g[v]) {
                if (side[u] == -1) {
                    side[u] = side[v] ^ 1;
                    q.push(u);
                } else {
                    is_bipartite = is_bipartite && (side[u] != side[v]);
                }
            }
        }
 
      }
    }
 
    return is_bipartite;
}
 
int main(){
    cin >> n >> m;
    
    side.assign(n, -1);
    g.resize(n);
    
    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b; 
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    if (isbipartite()){
        for(auto v : side){
        cout << v+1 << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
 
}