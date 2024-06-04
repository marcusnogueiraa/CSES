#include <bits/stdc++.h>

using namespace std;

int LIS(vector<int> &arr){
    vector<int> stacks;
    for(int i = 0; i < (int) arr.size(); i++){
        auto it = upper_bound(stacks.begin(), stacks.end(), arr[i]);
        if (it == stacks.end()) stacks.push_back(arr[i]);
        else *it = arr[i];
    }
    return stacks.size();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << LIS(arr) << endl;
}