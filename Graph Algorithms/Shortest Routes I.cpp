#include <bits/stdc++.h>

#define endl '\n'
#define il pair<ll, int>
#define ll long long

using namespace std;

const ll INFll = numeric_limits<ll>::max();
vector<vector<il>> G;
vector<ll> dist;

void dijk(int s){
    dist[s] = 0;
    priority_queue<il, vector<il>, greater<il>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        auto [wu, u] = pq.top();
        pq.pop();

        if (wu > dist[u]) continue;
        for(auto [w, to] : G[u]){
            if (dist[u] + w < dist[to]){
                dist[to] = dist[u] + w;
                pq.push({dist[to], to});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    G.assign(n, vector<il>());
    dist.assign(n, INFll);
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back({c, b});
    }

    dijk(0);

    for(int i = 0; i < n; i++) cout << dist[i] << " ";
    cout << endl;
    
}