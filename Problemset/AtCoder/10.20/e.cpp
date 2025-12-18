#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<array<i64, 3>> a(n);
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		a[i] = {x , x + y, i + 1};
	}
	sort(a.begin(), a.end(), [](const array<i64, 3> &a, const array<i64, 3> &b)->bool{
		i64 x = a[0] * (b[1] / __gcd(a[1], b[1]));
		i64 y = b[0] * (a[1] / __gcd(a[1], b[1]));
		return (x > y || (x == y && a[2] < b[2]));
	});
	for(auto e : a){
		cout << e[2] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}