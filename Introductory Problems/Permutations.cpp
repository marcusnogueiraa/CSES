#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
	int n;
	cin >> n;

	if (n == 3 || n == 2){
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	for(int i = n-1; i > 0; i=i-2) cout << i << " ";
	for(int i = n; i > 0; i=i-2) cout << i << " ";
	cout << endl;
}
