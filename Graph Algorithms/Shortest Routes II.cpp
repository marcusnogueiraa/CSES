#include <bits/stdc++.h>

#define endl '\n'
#define ii pair<int, int>
#define ll long long	
#define INF LLONG_MAX

using namespace std;

int n, m, q;

vector<vector<ll>> graph;
vector<vector<ll>> dist;

void floyd_warshall(){
	
	for(int i = 0; i < n; i++){
		graph[i][i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = graph[i][j];
		}
	}

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> q;

	graph.assign(n, vector<ll>(n, INF));
	dist.assign(n, vector<ll>(n, INF));

	for(int i = 0; i < m; i++){
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--; b--;

		graph[a][b] = min(w, graph[a][b]);
		graph[b][a] = min(w, graph[b][a]);
	}

	floyd_warshall();

	for (int i = 0; i < q; i++){
		int a, b; cin >> a >> b; a--; b--;
		cout << (dist[a][b] == INF ? -1 : dist[a][b]) << endl;
	}
}
