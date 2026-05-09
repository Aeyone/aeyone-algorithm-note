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
	vector<pair<char, int>> a(n);
	for (auto &[c, e] : a) {
		cin >> c;
		if (c == 'F') {
			cin >> e;
		}
	}

	priority_queue<int> h1;
	priority_queue<int, vector<int>, greater<int>> h2;
	i64 ans = 0, cur = 0; // cur : 当前h2的总和
	int cnt = 0; // 工人的数量

	for (int l = 0, r = 0; l < n; l = r) {
		if (a[l].first == 'W') {
			cnt ++, r ++;
			if (h1.size()) {
				auto e = h1.top();
				cur += e;
				h2.push(e);
				h1.pop();
			}
			ans += cur;
		} else {
			while (r < n && a[l].first == a[r].first) {
				r ++;
			}
			if (l > 0) {
				ans -= cur;
			}

			int len = r - l;
			vector<pair<i64, int>> v(len);
			vector<int> vis(len);

			for (int i = 0; i < len; i ++) {
				v[i] = {1ll * a[l + i].second * (len - i), i};
			}
			sort(v.begin(), v.end());

			i64 res = cur * (len + 1);

			int siz = h2.size();
			while (siz < cnt && v.size()) { // 只有h1为空才有可能
				auto [val, idx] = v.back();
				res += val;
				v.pop_back();
				siz ++;
			}

			vector<int> tmp;
			while (h2.size() && v.size() && 1ll * h2.top() * (len + 1) < v.back().first) {
				auto e = h2.top();
				auto [val, idx] = v.back();

				cur -= e;
				tmp.push_back(e);
				res += (val - e * (len + 1));

				h2.pop();
				v.pop_back();
			}
			ans += res;

			for (auto e : tmp) {
				cur += e;
				h2.push(e);
			}

			for (int i = 0; i < len; i ++) {
				auto [_, val] = a[l + i];
				cur += val;
				h2.push(val);
			}

			while (h2.size() > cnt) {
				auto e = h2.top();
				h1.push(e);
				cur -= e;
				h2.pop();
			}
		}
		// cerr << "l, r = " << l << ' ' << r << '\n';
		// cerr << "cur = " << cur << '\n';
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_ --) {
		solve();
	}
}