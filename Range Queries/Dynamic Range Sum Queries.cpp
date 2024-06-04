#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;

vector<ll> vet, seg;

ll build(int p, int l, int r){
    if (l == r) return seg[p] = vet[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r){
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

ll update(int i, ll x, int p, int l, int r){
    if (i < l || r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m) + update(i, x, 2*p+1, m+1, r);
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
        ll op, a, b;
        cin >> op >> a >> b;
        if (op == 1){
            update(--a, b, 1, 0, n-1);
        } else {
            cout << query(--a, --b, 1, 0, n-1) << endl;
        }
    }
}