#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

const int MAXV = 1e5+10;

vector<vector<int>> G(MAXV);
vector<int> father(MAXV);
vector<bool> vis(MAXV);

void bfs(int source, int query){
    queue<int> q;
    q.push(source);
    vis[source] = true;
    
    father[source] = source;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for (auto w : G[v]) if (!vis[w]){
            q.push(w); 
            vis[w] = true;
            father[w] = v;
        }
        if (vis[query]) return;
    }
}

list<int> path(int query){
    list<int> path;
    if (!vis[query]) return path;
    int actual = query;
    path.push_front(actual);
    while(actual != 0){
        actual = father[actual];
        path.push_front(actual);
    }
    return path;
}

int main(){
    cin.tie(0)->sync_with_stdio(0); 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    bfs(0, n-1);
    list<int> answer = path(n-1);

    if (answer.size() == 0){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << answer.size() << endl;
    for(auto n : answer){
        cout << n+1 << " ";
    }
    cout << endl;
}
