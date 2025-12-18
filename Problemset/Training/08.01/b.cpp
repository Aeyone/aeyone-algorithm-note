#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
vector<int> p;
vector<i64> s;

void build(int MAX){
	vector<bool> vis(MAX + 1);
	for(int i = 2; i <= MAX; i ++){
		if(!vis[i])
			p.push_back(i);
		for(int j = 0; j < p.size() && p[j] <= MAX / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	i64 sum = 0;
	for(auto &e : a)
		cin >> e, sum += e;

	sort(a.begin(), a.end(), greater<int>());
	while(sum < s[a.size()])
		sum -= a.back(), a.pop_back();
	
	cout << n - a.size() << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	build(6e6);
	s.resize(p.size() + 1);
	for(int i = 1; i <= p.size(); i ++)
		s[i] = s[i - 1] + p[i - 1];
	// cout << p.size() << '\n';
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}