#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

double qmi(double a, i64 b){
	double res = 1;
	for( ;b ; b >>= 1, a = a * a) if(b & 1) {
		res = a * res;
	}
	return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    double p = pow(1 - 1.0 / n, m);
    cout << n * (1 - p) << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(6);
    int t = 1;
    cin >> t;
    while (t --) {
        solve();
    }
}
