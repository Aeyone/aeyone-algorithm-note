#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static mt19937_64 rng (
    chrono::steady_clock::now().time_since_epoch().count()
);
#define randll(l, r) (uniform_int_distribution<long long>((l),(r))(rng))

void solve () {
    int n=randll(1,20),m=randll(1,5);
    cout<<n<<" "<<m<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = randll(1,2000);
    cout<<T<<endl;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}