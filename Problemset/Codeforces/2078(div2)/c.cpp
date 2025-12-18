#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> b(2 * n);
	for(int i = 0; i < 2 * n; i ++)
		cin >> b[i];
	sort(b.begin(), b.end());

	vector<i64> res(2 * n + 1), odd, even;
	for(auto e : b){
		if(odd.size() < n - 1)
			odd.push_back(e);
		else
			even.push_back(e);
	}
	for(auto e : even)
		res[1] += e;
	for(auto e : odd)
		res[1] -= e;

	res[0] = even.back();
	even.pop_back();
	for(int i = 2; i <= 2 * n; i ++)
		res[i] = ((i & 1) ? odd[i / 2 - 1] : even[i / 2 - 1]);
	
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