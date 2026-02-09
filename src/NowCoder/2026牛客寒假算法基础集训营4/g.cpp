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
	vector<int> f(n + 1);
	for (int i = 1; i <= n; i ++) {
		string s = to_string(i);
		int mul = 1;
		for (auto e : s) {
			mul *= (e - '0');
		}
		if (i != mul) {
			f[i] = f[mul] + 1;	
		}
	}
	for (int i = 0; i <= n; i ++) {
		cout << "i = " << i << " cnt = " << f[i] << '\n';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}