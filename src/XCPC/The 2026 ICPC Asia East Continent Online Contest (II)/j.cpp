#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, p;
	cin >> n >> p;
	vector<string> a(n);
	map<string, int> mp;
	mp["WrongProblem"] = 100;
	mp["SameProblem"] = 30;
	mp["UnreasonableLimitForProblem"] = 5;
	mp["WeakTestsForProblem"] = 3;
	mp["BadProblem"] = 1;
	int sum = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] == "UnreasonableProblemArrangement") {
			sum += 10;
			continue;
		}
		char c = a[i].back();
		if (c >= 'A' && c <= 'L') {
			string s = a[i].substr(0, a[i].size() - 1);
			sum += mp[s];
		}
	}
	cout << (sum <= p ? "Judger" : "Joker") << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	cin >> t;
	while (t --) {
		solve();
	}
}