#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {//按位构造计数题，通过拆分二进制位去构造，经典trick
	i64 x;
	cin >> x;
	vector<i64> a;
	while(x) {
		a.push_back(x & -x);
		x -= x & -x;
	}
	vector<int> ans;
	for(int i = 1; i <= __lg(a.back()); i ++) {
		ans.push_back(i);
	}
	a.pop_back();

	reverse(a.begin(), a.end());
	for(auto e : a) {
		ans.push_back(__lg(e) + 1);
	}
	cout << ans.size() << '\n';
	for(auto e : ans) {
		cout << e << ' ';
	}
	cout << '\n';
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