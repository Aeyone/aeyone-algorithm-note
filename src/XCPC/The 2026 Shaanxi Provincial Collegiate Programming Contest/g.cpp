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
	string s;
	cin >> s;
	int n = s.size();
	string s1, s2;
	for (int i = 0; i < n; i ++) {
		if (i & 1) s1 += 'W', s2 += 'B';
		else s2 += 'W', s1 += 'B';
	}
	auto run = [&](string t)-> int {
		int l = 0, r = n - 1;
		while (l < n && s[l] == t[l])  l ++;
		while (r >= 0 && s[r] == t[r]) r --;
		return max(0, r - l + 1);
	};
	cout << min(run(s1), run(s2)) << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	while (_ --) {
		solve();
	}
}