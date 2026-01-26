#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

const int MOD = 998244353;

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	auto check = [&](string s)->array<int, 2>{
		int x = 0;
		while (s[x] != '+') {
			x ++;
		}
		int res1 = stoi(s.substr(0, x));
		int res2 = stoi(s.substr(x + 1, s.size() - x - 1));
		return {res1, res2};
	};
	array<int, 2> z1 = check(s1);
	array<int, 2> z2 = check(s2);
	double res1 = z1[0] * z2[0] - z1[1] * (-z2[1]);
	double res2 = z1[0] * (-z2[1]) + z1[1] * z2[0];
	res1 /= z2[0] * z2[0] + z2[1] * z2[1];
	res2 /= z2[0] * z2[0] + z2[1] * z2[1];
	cout << res1 << ' ' << res2 << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}