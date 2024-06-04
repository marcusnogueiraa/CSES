#include <bits/stdc++.h>

#define end '\n'
#define ll long long

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;

    cin >> n >> q;
    ll vet[n];
    ll pref[n];

    for(int i = 0; i < n; i++) cin >> vet[i];

    pref[0] = vet[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i-1] + vet[i];

    for(int i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        a--; b--;

        ll res = pref[b];
        if (a != 0) res-= pref[a-1];

        cout << res << endl;
    }
}