#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	multiset<int> a, b;
	i64 sum = 0;
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		sum += x;
		a.insert(x);
	}
	for(int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		sum += x;
		b.insert(x);
	}
	int cnt = 0;
	for(auto e : b) {
		auto it = a.lower_bound(m - e);
		if(it != a.end()) {
			a.erase(it);
			cnt ++;
		}
	}
	cout << sum - 1ll * cnt * m << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}