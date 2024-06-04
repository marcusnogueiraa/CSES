#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	int n;
	cin >> n;
	int vet[n];
	for(int i = 0; i < n-1; i++) cin >> vet[i];
	sort(vet, vet+n-1);
	bool as_find = false;
	for(int i = 0; i < n-1; i++){
		if (vet[i] != i+1){
			cout << i+1 << endl;
			as_find = true;
			break;
		}
	}

	if (!as_find) cout << n << endl;
}
