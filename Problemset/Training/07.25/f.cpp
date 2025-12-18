#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
vector<int> p;

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
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	map<int, bool> mp;
	auto divide = [&](int x)->bool{
		bool res = false;
		for(int i = 0; (i < p.size() && x >= p[i]); i ++){
			if(x % p[i] == 0){
				res |= (mp.find(p[i]) != mp.end());
				mp[p[i]] = true;
				while(x % p[i] == 0)
					x /= p[i];
			}
		}
		if(x > 1){
			res |= (mp.find(x) != mp.end());
			mp[x] = true;
		}
		return res;
	};
	bool ok = false;
	for(auto e : a)
		ok |= divide(e);

	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	build(1e5);
	// cout << p.size() << '\n';
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}