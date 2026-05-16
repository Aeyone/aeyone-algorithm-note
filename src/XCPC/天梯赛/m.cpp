#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL

void solve() {
	int n;
	cin >> n;
	vector<array<int, 4>> a(n);
	for (auto &[t, idx, id, y] : a) {
		cin >> t >> idx >> id >> y;
	}
	reverse(a.begin(), a.end());
	vector<int> ans = {-1};

	multiset<array<int, 2>> curNomal, curOld;
	vector<int> cur(n + 1, -1);

	for (int i = 1, j = 0; a.size() || curNomal.size() || curOld.size(); i ++) {
		ans.push_back(-1);

		while (a.size() && a.back()[0] <= i) {
			auto [t, idx, id, y] = a.back();
			cur[idx] = id;
			if (y >= 80) {
				curOld.insert({idx, id});
			} else {
				curNomal.insert({idx, id});
			}
			a.pop_back();
		}
		if (curOld.size()) {
			ans[i] = (*curOld.begin())[1];
			curOld.erase(curOld.begin());
		} else if (i <= n && cur[i] != -1) {
			ans[i] = cur[i];
			if (curOld.find({i, cur[i]}) != curOld.end()) {
				curOld.erase(curOld.find({i, cur[i]}));
			}
			if (curNomal.find({i, cur[i]}) != curNomal.end()) {
				curNomal.erase(curNomal.find({i, cur[i]}));
			}
		} else if (curNomal.size()) {
			ans[i] = (*curNomal.begin())[1];

			curNomal.erase(curNomal.begin());
		}
	}
	for (int i = 1; i < ans.size(); i ++) {
		if (ans[i] != -1) {
			string s = to_string(ans[i]);
			while (s.size() < 5) {
				s = "0" + s;
			}
			cout << i << ' ' << s << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --) {
		solve();
	}
}