#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<string> a(4);
	for (int i = 0; i < 4; i ++) {
		cin >> a[i];
	}
	int s[4] = {2000, 2000, 2000, 2000}, combo[4] {}, zero[4] {};

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 4; j ++) {
			if (a[j][i] == 'H') {
				combo[j] ++;
			} else {
				combo[j] = 0;
			}
			
			if (combo[j] == 100) {
				// ok = true;
				combo[j] = 0;
				for (int k = 0; k < 4; k ++) if (k != j) {
					if (zero[k]) continue;
					s[k] += 30;
				}
			}

			if (zero[j]) continue;
			if (a[j][i] == 'J') {
				s[j] -= 50;
			} else if (a[j][i] == 'A') {
				s[j] -= 100;
			} else if (a[j][i] == 'M') {
				s[j] -= 200;
			}
		}
		// bool ok = false;
		// for (int j = 0; j < 4; j ++) {
		// 	if (combo[j] == 100) {
		// 		ok = true;
		// 		for (int k = 0; k < 4; k ++) if (k != j) {
		// 			if (zero[k]) continue;
		// 			s[k] += 30;
		// 		}
		// 	}
		// }
		// if (ok) {
		// 	for (int j = 0; j < 4; j ++) {
		// 		combo[j] = 0;
		// 	}
		// }

		for (int j = 0; j < 4; j ++) {
			if (s[j] <= 0) {
				s[j] = 0;
				zero[j] = 1;
			}
			s[j] = min(s[j], 2000);
		}
	}
	for (int j = 0; j < 4; j ++) {
		cout << s[j] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}

