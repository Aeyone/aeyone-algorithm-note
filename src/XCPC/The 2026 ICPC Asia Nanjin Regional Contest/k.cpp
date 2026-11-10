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
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	auto check = [&](string s)-> int {
		if (s.size() == 2 && s[1] == '/') return 10;
		int res = 0;
		if (s[0] != 'X') res += (s[0] - '0');
		else res += 10;

		if (s.size() == 2) {
			if (s[1] != 'X') res += (s[1] - '0');
			else res += 10;
		}

		return res;
	};

	int cur = 0, r = 1, cnt = 0;
	vector<int> ans(n);

	for (int i = 0; i < s.size(); ) {
		auto e = s[i];
		if (r < 10) {
			if (e == 'X') {
				ans[cur] += 10;
				string sub = s.substr(i + 1, 2);
				ans[cur] += check(sub);
				r ++;
			}else if (e == '/') {
				ans[cur] += 10 - (s[i - 1] - '0');
				string sub = s.substr(i + 1, 1);
				ans[cur] += check(sub);
				r ++;
				cnt = 0;
			} else {
				ans[cur] += (s[i] - '0');
				cnt ++;
				if (cnt == 2) r ++, cnt = 0;
			}
			i ++;
		} else {
			if (e == 'X') {
				ans[cur] += 10;
				string sub = s.substr(i + 1, 2);
				ans[cur] += check(sub);
				i += 3;
				r ++;
			}else if (e == '/') {
				ans[cur] += 10 - (s[i - 1] - '0');
				string sub = s.substr(i + 1, 1);
				ans[cur] += check(sub);
				i += 2;
				cnt = 0;
				r ++;
			} else {
				ans[cur] += (s[i] - '0');
				cnt ++;
				if (cnt == 2) r ++, cnt = 0;
				i ++;
			}
			if (r > 10) {
				r = 1;
				cur ++;
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		cout << ans[i] << ' ';
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