#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a = {k};
	bool ok = false;
	for(int i = 1; i <= n; i ++){
		vector<int> t(1 << i);
		for(int j = 0; j < a.size(); j ++){
			t[j * 2] = a[j] / 2;
			t[j * 2 + 1] = (a[j] + 1) / 2;
			ok |= (a[j] & 1);
		}
		a = t;
	}
	cout << ok << '\n';
	for(auto e : a){
		cout << e << ' ';
	}
	cout << '\n';
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