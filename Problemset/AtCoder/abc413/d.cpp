#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool cmp(const int &a, const int &b){
	return abs(a) < abs(b);
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	sort(a.begin(), a.end(), cmp);
	int c0 = count(a.begin(), a.end(), -a[0]);
	int c1 = count(a.begin(), a.end(), a[0]);

	if(c1 + c0 == n && (abs(c1 - c0) <= 1)){
		cout << "Yes" << '\n';
		return;
	}

	bool ok = true;
	for(int i = 0; i < n - 1; i ++){
		ok &= ((i64)a[i + 1] * a[0] == (i64)a[1] * a[i]);
	}
	if(ok)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}