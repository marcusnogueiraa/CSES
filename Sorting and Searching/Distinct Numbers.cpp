#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> vet(n);
    for(int i = 0; i < n; i++) cin >> vet[i];
    sort(vet.begin(), vet.end());
    int dif = 1;
    for(int i = 1; i < n; i++){
        if (vet[i] != vet[i-1]) dif++;
    }
    cout << dif << endl;
}
