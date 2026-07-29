#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l,ll r){
    return uniform_int_distribution<ll>(l,r)(rng);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXSUM = 100000;

    int T = 1;
    cout << T << "\n";

    int used = 0;

    for(int t=0;t<T;t++){
        int n = Rand(1, 100);
        cout << n << '\n';
        for (int i = 0; i < n; i ++) {
            cout << Rand(1, n) << ' ';
        }
        cout << '\n';
    }

    return 0;
}