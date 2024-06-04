#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int main(){
	int n;
	cin >> n;
	ll vet[n];
	for(int i = 0; i < n; i++) cin >> vet[i];
	ll moves = 0;
	for(int i = 1; i < n; i++){
		if (vet[i-1] > vet[i]){
			moves += vet[i-1] - vet[i];
			vet[i] = vet[i-1];
		}
	}
	cout << moves << endl;
}
