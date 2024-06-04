#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;
vector<ll> arr;
vector<ll> seg;
vector<ll> lazy;

void up_lazy(int p, int l, int r){
    seg[p] += (ll) (r-l+1)*lazy[p];
    if (l != r){
        lazy[2*p] += lazy[p];
        lazy[2*p+1] += lazy[p];
    }
    lazy[p] = 0;
}

void build(int p, int l, int r){
    if (l == r) {
        seg[p] = arr[l];
        return;
    }
    int m = (l+r) / 2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    seg[p] = seg[2*p] + seg[2*p+1];
}

void update(ll value, int a, int b, int p, int l, int r){
    up_lazy(p, l, r);
    if (a > r || b < l) return;
    if (l >= a && r <= b){
        lazy[p] += value;
        up_lazy(p, l, r);
        return;
    }
    int m = (l+r) / 2;
    update(value, a, b, 2*p, l, m);
    update(value, a, b, 2*p+1, m+1, r);
    seg[p] = seg[2*p] + seg[2*p+1];
}

ll query(int a, int b, int p, int l, int r){
    up_lazy(p, l, r);
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int main(){
    cin >> n >> q;
    
    arr.resize(n);
    seg.resize(n*4);
    lazy.assign(n*4, 0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    build(1, 0, n-1);

    for(int i = 0; i < q; i++){
        int op;
        cin >> op;

        if (op == 2){
            int k;
            cin >> k;
            k--;
            cout << query(k, k, 1, 0, n-1) << endl;
        } else {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            a--; b--;
            update(u, a, b, 1, 0, n-1);
        }

    }
}