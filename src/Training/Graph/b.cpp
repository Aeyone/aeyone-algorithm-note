#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

const int N = 110;
int a[N][N];

void solve() {
	int n;
	scanf("%d", &n);
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	for (int i = 0; i <= n; i ++) {
		a[0][i] = 1;
		a[i][0] = 1;
		a[n + 1][i] = 1;
		a[i][n + 1] = 1;
	}
	int cur = 0, x = 1, y = 0, num = 1;
	while (1) {
		if (num > n * n) break;
		int nx = x + dx[cur], ny = y + dy[cur];
		if (!a[nx][ny]) {
			a[nx][ny] = num ++;
			x = nx;
			y = ny;
		} else {
			cur = (cur + 1) % 4;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}