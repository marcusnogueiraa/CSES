#include <bits/stdc++.h>

#define ii pair<int, int>
#define f first
#define s second
#define endl '\n'

using namespace std;

const int MAXS = 2000;

int n, m;
int startI, startJ;
char mat[MAXS][MAXS];
ii pt[MAXS][MAXS];

list<char> path;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool is_poss(int i, int j){
    if (i >= 0 && i < n && j >= 0 && j < m) return true;
    return false;
}

ii bfs(int i, int j){
    mat[i][j] = '#';
    queue<ii> q;
    q.push(ii(i, j));

    while(!q.empty()){
        ii cp = q.front(); q.pop();

        for(int k = 0; k < 4; k++){
            int ni = cp.f + di[k];
            int nj = cp.s + dj[k];

            if(is_poss(ni, nj) && mat[ni][nj] != '#'){
                q.push(ii(ni, nj));
                pt[ni][nj] = ii(cp.f, cp.s);

                if(mat[ni][nj] == 'B') return ii(ni, nj);
                mat[ni][nj] = '#';
            } 
        }

    }

    return ii(-1, -1);
}

void makepath(int i, int j) {
    while (i != startI || j != startJ) {
        ii bp = pt[i][j];
        int ni = bp.f;
        int nj = bp.s;

        if (ni > i) path.push_front('U');
        else if (ni < i) path.push_front('D');
        else if (nj > j) path.push_front('L');
        else if (nj < j) path.push_front('R');

        i = ni;
        j = nj;
    }
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] == 'A'){
                startI = i; startJ = j;
            }
        }
    }


    ii res = bfs(startI, startJ);
    if (res.f == -1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    makepath(res.f, res.s);
    cout << path.size() << endl;

    for(auto c : path){
        cout << c;
    }

    cout << endl;
}
