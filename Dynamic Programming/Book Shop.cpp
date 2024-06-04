#include <bits/stdc++.h>

#define endl '\n'
#define INF INT_MAX

using namespace std;

int n, x;
vector<int> price;
vector<int> pages;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;

    price.resize(n);
    pages.resize(n);

    for(int i = 0; i < n; i++) cin >> price[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << endl;
}
