#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;
const int N = 30;

i64 c[N][N], fac[N];

void init() {
	fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    for (int i = 0; i < N; i ++) {
	    for (int j = 0; j <= i; j ++) {
	        if (!j){
	            c[i][j] = 1;
	        }else{
	            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
	        }
	    }
	}
}


void solve() {
	int n;
	cin >> n;
	cout << c[n][n / 2]  * fac[n / 2 - 1] * fac[n / 2 - 1] / 2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	init();
	int _ = 1;
	while (_ --) {
		solve();
	}
}