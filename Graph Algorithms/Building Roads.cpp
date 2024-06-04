#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back

const int MAXV = 10e5+10;
vector<vector<int>> G(MAXV);
vector<bool> vis(MAXV, false);

void dfs(int s){
    vis[s] = true;

    for (auto w : G[s]) if (!vis[w]){
        dfs(w);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b; 
        a--; 
        b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    list<int> components;
    for(int i = 0; i < n; i++) if (!vis[i]){
        dfs(i);
        components.push_back(i);
    }

    auto it = components.begin();
    auto last = components.end();
    --last;
    cout << components.size() - 1 << endl;
    while(it != last){
        cout << *it+1 << " " << *(next(it))+1 << endl;
        ++it;
    }

}