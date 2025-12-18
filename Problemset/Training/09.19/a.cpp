#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<i64> a(n), suf(n + 1);
	for(int i = 0; i < n; i ++){
		a[i] = s[i] - '0';
	}
	reverse(a.begin(), a.end());
	while(a.back() == 0)
		a.pop_back();
	
	for(int i = a.size() - 1; i >= 0; i --){
		suf[i] = a[i] + suf[i + 1];
	}
	vector<int> res(n);
	for(int i = 0; i < n; i ++){
		res[i] = suf[i] % 10;
		suf[i + 1] += suf[i] / 10;
	}
	i64 t = suf[n];
	while(t > 0){
		res.push_back(t % 10);
		t /= 10;
	}
	while(!res.back())
		res.pop_back();
	reverse(res.begin(), res.end());
	for(auto e : res)
		cout << e;
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}