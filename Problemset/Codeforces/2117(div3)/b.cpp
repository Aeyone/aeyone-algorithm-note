#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> res;
	for(int x = 1; x <= n; x += 2)
		res.push_back(x);

	int x = res.back();
	if(x < n)
		x ++;
	else
		x --;
	while(x > 0){
		res.push_back(x);
		x -= 2;
	}
	for(auto e : res)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}