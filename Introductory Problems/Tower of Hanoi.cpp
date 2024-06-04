#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

void hanoi(int n, int s, int d, int a){
    if (n == 1){
        cout << s << " " << d << endl;
        return;
    }
    hanoi(n-1, s, a, d);
    cout << s << " " << d << endl;
    hanoi(n-1, a, d, s);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 1, 3, 2);
}