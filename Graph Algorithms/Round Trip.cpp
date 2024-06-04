#include <bits/stdc++.h>

#define ii pair<int, int>
#define endl '\n'

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v, int par){
	visited[v] = true;
	for(int u : g[v]){
		if (u == par) continue;
		if (visited[u]){
			cycle_end = v;
			cycle_start = u;
			return true;
		}
		parent[u] = v;
		if (dfs(u, parent[u]))
			return true;
	}
	return false;
}

list<int> find_cycle(){
	visited.assign(n, false);
	parent.assign(n, -1);
	cycle_start = -1;

	list<int> cycle;

	for(int v = 0; v < n; v++){
		if (!visited[v] && dfs(v, parent[v]))
				break;
	}

	if (cycle_start != -1) {
		cycle.push_back(cycle_start);
		for(int v = cycle_end; v != cycle_start; v = parent[v])
				cycle.push_back(v);
		cycle.push_back(cycle_start);
	}

	return cycle;
}

int main(){
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	list<int> cycle {find_cycle()};

	if (cycle.size() == 0){
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << cycle.size() << endl;	
		for(int v : cycle){
			cout << v+1 << " ";
		}
		cout << endl;
	}
	
}
