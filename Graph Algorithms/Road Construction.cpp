#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int maxSz = -1;
int compN;
vector<int> id, sz;

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q){
    p = find(p), q = find(q);
    if (p == q) return;
    if (sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
    
    compN--;
    maxSz = max(maxSz, sz[q]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    compN = n;
    id.resize(n);
    sz.assign(n, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        uni(a, b);
        cout << compN << " " << maxSz << endl;
    }
}