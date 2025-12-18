#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	bool ok = true;
	for(int i = n; i >= 1; i --) {
		bool isok = false;
		int cnt = 0;
		for(int j = 0; j < n; j ++) if(a[j] == i){
			for(int k = 0; k < (n - i + 1) && j + k < n; k ++){
				ok &= (a[j + k] == i);
				a[j + k] --;
			}
			break;
		}
	}
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}