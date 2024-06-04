#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> vet;
vector<int> seg;

const int INF = numeric_limits<int>::max();

int build(int p, int l, int r){
    if (l == r) return seg[p] = vet[l];
    int m = (l+r)/2;
    return seg[p] = min(build(p*2, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r){
    // Intervalo completamente disjunto
    if (b < l || a > r) return INF;
    // Intervalo completamente contido
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;
    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vet.resize(n);
    seg.resize(n*4);
    for(int i = 0; i < n; i++) cin >> vet[i];

    build(1, 0, n-1);

    for(int i = 0; i < q; i++){
        int a, b; 
        cin >> a >> b;
        a--; b--;

        cout << query(a, b, 1, 0, n-1) << endl;
    }
}