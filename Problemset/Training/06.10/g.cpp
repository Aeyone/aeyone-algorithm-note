#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n, c[N];

void add(int x, int v) {
	while (x <= n + 1)
		c[x] += v, x += x & -x;
}

int ask(int x) {
	int ans = 0;
	while (x)
		ans += c[x], x -= x & -x;
	return ans;
}

void solve() {
	memset(c, 0, sizeof c);
	cin >> n;
	vector<pii> p(n);
	for(int i = 0; i < n; i ++){
		int a, b;
		cin >> a >> b;
		p[i] = {b, a};
	}
	sort(p.begin(), p.end());
	int t = n;
	for(auto &[a, b] : p){
		a = t --;
		swap(a, b);
	}
	sort(p.begin(), p.end());

	i64 ans = 0;
	for(auto [_, e] : p){
		ans += ask(e);
		add(e, 1);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}