#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n;	
	cin >> n;
	vector<int> a(2 * n);
	for(int i = 0; i < 2 * n; i ++){
		cin >> a[i];
	}
	vector<int> d(2 * n);
	for(int i = 0; i < 2 * n; i ++){
		for(int j = 0; j < 2 * n; j ++){
			d[i] += abs(a[i] - a[j]);
		}
		cout << d[i] << ' ';
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