#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int long long
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

static mt19937_64 rng(
    chrono::steady_clock::now().time_since_epoch().count()
);

#define randInt(l, r) ( uniform_int_distribution<int>((l),(r))(rng) )//int类型


void solve() {
	int n;
	cin >> n;
	vector<array<int, 2>> p(n);
	for(auto &[x, y] : p){
		cin >> x >> y;
	}
	int cnt = 0;
	while(cnt < min(60ll, n)){
		int u1 = randInt(0, n - 1), u2 = randInt(0, n - 1);
		if(u1 == u2){
			continue;
		}
		auto [x1, y1] = p[u1];
		auto [x2, y2] = p[u2];
		int dx = x2 - x1, dy = y2 - y1;
		int c = 0;
		for(int i = 0; i < n; i ++){
			if(i == u1 || i == u2){
				continue;
			}
			auto [x, y] = p[i];
			if(-dy * x + dx * y + 1ll * dy * x1 - 1ll * dx * y1 == 0){
				c ++;
			}
		}
		if(c + 2 > n / 2){
			cout << "Yes" << '\n';
			cout << -dy << ' ' << dx << ' ' << 1ll * dy * x1 - 1ll * dx * y1 << '\n';
			return;
		}
		cnt ++;
	}
	cout << "No" << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}