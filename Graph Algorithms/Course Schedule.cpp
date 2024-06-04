#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); 
    vector<int> degree(n, 0);
    vector<int> res;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;

        degree[b]++;
        adj[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
        if (degree[i] == 0) res.push_back(i);
    }

    int ini = 0;

    while(ini < (int) res.size()){

        int current = res[ini];
        ini++;

        for(int i = 0; i < (int) adj[current].size(); i++){
            int v = adj[current][i];
            degree[v]--;
            if (degree[v] == 0) res.push_back(v);
        }
    }

    if (res.size() < n){
        cout << "IMPOSSIBLE" << endl;
    } else {
        for(int num : res){
            cout << num+1 << " ";
        }
        cout << endl;
    }

}