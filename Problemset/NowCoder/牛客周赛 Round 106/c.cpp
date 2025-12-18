#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 20 + 10;
const int inf = 0x3f3f3f3f;
int f[10][10][N];

void solve() {
	int n, L1, R1, L2, R2;
	cin >> n >> L1 >> R1 >> L2 >> R2;
	vector<int> a(n - 2);
	for(auto &e : a)
		cin >> e;

	vector<pair<int, int>> v;
	for(int i = 0; i < 10; i ++){
		for(int j = 0; j < 10; j ++){
			bool ok = true;
			for(int k = 0; k < n - 2; k ++)
				ok &= (f[i][j][k] == a[k]);
			if(ok)
				v.push_back({i, j});
		}
	}
	int a1 = inf, a2 = inf;
	for(auto [t1, t2] : v){
		int x = inf, y = inf;
		for(int i = L1; i <= min(R1, L1 + 10); i ++){
			if(i % 10 == t1){
				x = i;
				break;
			}
		}
		for(int i = L2; i <= min(R2, L2 + 10); i ++){
			if(i % 10 == t2){
				y = i;
				break;
			}
		}
		if(x != inf && y != inf && (x < a1 || (x == a1 && y < a2)))
			a1 = x, a2 = y;
	}
	if(a1 != inf && a2 != inf){
		cout << a1 << ' ' << a2 << '\n';
	}else
		cout << -1 << ' ' << -1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	for(int i = 0; i < 10; i ++){
		for(int j = 0; j < 10; j ++){
			f[i][j][0] = (i * j) % 10;
			f[i][j][1] = (i * j * j) % 10;
			for(int k = 2; k < N; k ++){
				f[i][j][k] = (f[i][j][k - 1] * f[i][j][k - 2]) % 10;
			}
			// cout << "i = " << i << " j = " << j << '\n';
			// for(int k = 0; k < N; k ++)
			// 	cout << f[i][j][k] << ' ';
			// cout << '\n';
		}
	}
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}