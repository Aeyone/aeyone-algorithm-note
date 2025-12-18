#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//二进制好题
	int a1, b;
	cin >> a1 >> b;
	int ans = b - a1;
	for(int i = 0; i <= b - a1; i ++){
		int a = a1 + i, cur = 30;
		while(cur >= 0 && !((a >> cur & 1) && !(b >> cur & 1)))
			cur --;
		int A = 0, B = 0;
		for(int i = cur; i >= 0; i --){
			A += (1 << i) * (a >> i & 1);
			B += (1 << i) * (b >> i & 1);
		}
		ans = min(ans, A - B + 1 + i);
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}