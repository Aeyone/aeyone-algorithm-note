#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve1() {
	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i ++) cin >> p[i];
	for (auto e : p) cout << e << ' ';
	cout << '\n';
	swap(p[0], p[1]);
	sort(p.begin() + 1, p.end());
	int cnt = 1;

	do {
		for (auto e : p) cout << e << ' ';
		cout << '\n';
		cnt ++;
	} while (cnt < n && next_permutation(p.begin() + 1, p.end()));
}

void solve2() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> a[i][j];
		}
	}
	sort(a.begin(), a.end());
	if (a[0][0] == a[1][0]) {
		for (auto e : a.back()) cout << e << ' ';
		cout << '\n';
	} else {
		for (auto e : a.front()) cout << e << ' ';
		cout << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string s;
	cin >> s;
	if (s == "first") {
		solve1();
	} else {
		solve2();
	}
}