#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int N = 100;
int c[N][N];

void init() {
	// c[a][b] 表示从a个苹果中选b个的方案数
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
	int n, k;
	cin >> n >> k;
	int len = __lg(n), ans = (len >= k);
	for (int i = len - 1; i > 0; i --) {
		for (int j = i; j >= 0 && i + j + 1 > k; j --) {
			ans += c[i][j];
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	init();
	while (_ --) {
		solve();
	}
}