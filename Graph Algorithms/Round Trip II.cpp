#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n, m;
vector<vector<int>> g;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v){
	color[v] = 1;
	for (int u : g[v]){
		if (color[u] == 0){
			parent[u] = v;
			if (dfs(u))
				return true;
		} else if (color[u] == 1){
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;
}

list<int> find_cycle(){
	color.assign(n, 0);
	parent.assign(n, -1);
	cycle_start = -1;

	list<int> cycle;

	for(int v = 0; v < n; v++){
		if (color[v] == 0 && dfs(v))
			break;
	}

	if (cycle_start != -1){
		cycle.push_back(cycle_start);
		for(int v = cycle_end; v != cycle_start; v = parent[v])
				cycle.push_back(v);

		cycle.push_back(cycle_start);
		reverse(cycle.begin(), cycle.end());
	}

	return cycle;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		a--; b--;

		g[a].push_back(b);
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
