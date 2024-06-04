#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
	string str;
	cin >> str;
	unordered_map<char, int> lts = {
		{'A', 0},
		{'C', 0},
		{'G', 0},
		{'T', 0}	
	};

	int MAXN = -1;
	char ant = 'z';
	for(int i = 0; i < str.length(); i++){
		if (ant != 'z' && ant != str[i]) lts[ant] = 0;
		int val = ++lts[str[i]];
		if (val > MAXN) MAXN = val;
		ant = str[i];
	}

	cout << MAXN << endl;
}
