#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAXS = 1e3;
char mat[MAXS][MAXS];

void dfs(int i, int j){
    mat[i][j] = '#';
    
    if (i < n - 1 && mat[i+1][j] != '#') {
        dfs(i+1, j);
    } if (i > 0 && mat[i-1][j] != '#') {
        dfs(i-1, j);
    } if (j < m - 1 && mat[i][j+1] != '#') {
        dfs(i, j+1);
    } if (j > 0 && mat[i][j-1] != '#') {
        dfs(i, j-1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] != '#'){
                dfs(i, j);
                cout << endl;
                res++;
            }
        }
    }

    cout << res << endl;
}
