#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 0x3f3f3f3f3f3f3f3fLL

void solve1() {
	int n;
	cin >> n;
	vector<int> p(n);
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i ++) cin >> p[i];
	a[0] = p;

	swap(p[0], p[1]);
	sort(p.begin() + 1, p.end());
	int cnt = 1;

	do {
		cerr << "cnt = " << cnt << '\n';
		a[cnt ++] = p;
	} while (cnt < n && next_permutation(p.begin() + 1, p.end()));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}

	// sort(a.begin(), a.end());
	// if (a[0][0] == a[1][0]) {
	// 	for (auto e : a.back()) cout << e << ' ';
	// 	cout << '\n';
	// } else {
	// 	for (auto e : a.front()) cout << e << ' ';
	// 	cout << '\n';
	// }
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
	solve1();
}