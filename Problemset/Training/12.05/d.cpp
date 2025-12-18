#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	s = "x" + s;
	vector<int> a(n + 1);
	cerr << "a = ";
	for(int i = 1; i <= n; i ++){
		a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1);
		cerr << a[i] << ' ';
	}
	cerr << '\n';
	vector<vector<int>> stmx(n + 1, vector<int>(20));
	vector<vector<int>> stmn(n + 1, vector<int>(20));
	for(int i = 0; i <= n; i ++){
		stmx[i][0] = a[i];
		stmn[i][0] = a[i];
	}
	for(int p = 1; n >> p > 0; p ++){
		for(int i = 0; i - 1 + (1 << p) <= n; i ++){
			stmx[i][p] = max(stmx[i][p - 1], stmx[i + (1 << (p - 1))][p - 1]);
			stmn[i][p] = min(stmn[i][p - 1], stmn[i + (1 << (p - 1))][p - 1]);
		}
	}
	auto query = [&](int l, int r)->array<int, 2>{
		if(l <= r){
			int p = __lg(r - l + 1);
			return {max(stmx[l][p], stmx[r - (1 << p) + 1][p]), min(stmn[l][p], stmn[r - (1 << p) + 1][p])};
		}
		return {0, 0};
	};
	while(m --){
		int l, r;
		cin >> l >> r;
		auto [x1, y1] = query(r, n);
		auto [x2, y2] = query(0, l - 1);
		cerr << "x1 = " << x1 << " y1 = " << y1 << '\n';
		cerr << "x2 = " << x2 << " y2 = " << y2 << '\n';
		if(l == 1){
			cout << x1 - y1 + 1 << '\n';
		}else if(r == n){
			cout << x2 - y2 + 1 << '\n';
		}else{
			int x = max(x1 - (a[r] - a[l - 1]), x2);
			int y = min(y1 - (a[r] - a[l - 1]), y2);
			cout << x - y + 1 << '\n';
		}
	}
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