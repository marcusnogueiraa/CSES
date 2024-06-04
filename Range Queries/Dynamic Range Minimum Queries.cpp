#include <bits/stdc++.h>

using namespace std;

vector<int> seg, vet;

const int INF = numeric_limits<int>::max();

int build(int p, int l, int r){
    if (l == r) return seg[p] = vet[l];
    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r){
    if (b < l || a > r) return INF;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;
    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r)); 
}

int update(int i, int x, int p, int l, int r){
    if (i < l || i > r) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vet.resize(n);
    seg.resize(4*n);
    for(int i = 0; i < n; i++) cin >> vet[i];

    build(1, 0, n-1);

    for(int i = 0; i < q; i++){
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1){
            a--;
            update(a, b, 1, 0, n-1);
        }
        else{
            a--; b--;
            cout << query(a, b, 1, 0, n-1) << endl;
        }
    }
}