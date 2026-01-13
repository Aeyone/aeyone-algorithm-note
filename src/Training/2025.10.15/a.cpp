#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//同余定理：设a > b，则(a − b) | a 且 (a − b) | b 。
	int n, q;
	cin >> n >> q;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i ++){
		b[i] = abs(a[i] - a[i + 1]);
	}
	vector<vector<int>> st(n - 1, vector<int>(22));
	for(int i = 0; i < n - 1; i ++){
		st[i][0] = b[i];
	}
	for(int p = 1; (n - 1) >> p > 0; p ++){
		for(int i = 0; i + (1 << p) <= n - 1; i ++){
			st[i][p] = __gcd(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->int{
		if(l == r){
			return 0;
		}
		r --;
		int p = log2(r - l + 1);
		return __gcd(st[l][p], st[r - (1 << p) + 1][p]);
	};
	while(q --){
		int l, r;
		cin >> l >> r;
		l --, r --;
		cout << query(l, r) << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}