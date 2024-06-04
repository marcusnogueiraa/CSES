#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007;

using namespace std;

ll fastexp(ll a, ll b){
    a %= MOD;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        cout << fastexp(a, b) << endl;
    }
}