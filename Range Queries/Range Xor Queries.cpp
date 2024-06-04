#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

vector<int> vet, prefix;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    vet.resize(n);
    prefix.resize(n);
    
    for(int i = 0; i < n; i++) cin >> vet[i];
    prefix[0] = vet[0];
    for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] ^ vet[i];
    
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        int res = prefix[r]^prefix[l-1];
        cout << res << endl;
    }
}