#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a, b;
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (i < n / 2) {
			a.push_back(x);
		} else {
			b.push_back(x);
		}
	}
	int ans = 0;
	auto run = [&](vector<int> &a, vector<int> &tar)->void{
		for (int mask = 0; mask < 1 << a.size(); mask ++) {
			int sum = 0;
			for (int i = 0; i < a.size(); i ++) {
				if (mask >> i & 1) {
					sum = (sum + a[i]) % m;
				}
			}
			ans = max(ans, sum);
			tar.push_back(sum);
		}
	};
	vector<int> p, q;
	run(a, p);
	run(b, q);
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());

	for (int i = 0, j = q.size() - 1; i < p.size() && j >= 0; i ++) {
		while(p[i] + q[j] >= m) {
			j --;
		}
		ans = max(ans, p[i] + q[j]);
	}
	cout << ans << '\n';

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}