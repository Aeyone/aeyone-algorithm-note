#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int N = 3e5 + 10;
int c[N], c1[N];
int ans = 1, mx = 0;

void add1(int x, int v) {
	while (x <= N)
		c[x] += v, x += x & -x;
}

int ask1(int x) {
	int ans = 0;
	while (x)
		ans += c[x], x -= x & -x;
	return ans;
}

void add2(int x, int v) {
	while (x <= N)
		c1[x] += v, x += x & -x;
}

int ask2(int x) {
	int ans = 0;
	while (x)
		ans += c1[x], x -= x & -x;
	return ans;
}
void range_add(int l, int r, i64 x) {
    add1(l, x), add1(r + 1, -x);
    add2(l, x * (l - 1)), add2(r + 1, -x * r);
}

i64 pre_sum(int x) {
    return ask1(x) * x - ask2(x);
}

i64 range_sum(int l, int r) {
    return pre_sum(r) - pre_sum(l - 1);
}

void solve() {
	int l, r;
	cin >> l >> r;
	int cnt = range_sum(l, r);
	if(cnt == 0){
		range_add(l, r, 1);
		ans += max(0, r - l + 1 - mx);
		mx = max(mx, r - l + 1);
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