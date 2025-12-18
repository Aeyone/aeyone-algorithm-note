#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mp;
	for(int i = 0; i < n; i ++)
		cin >> a[i], mp[a[i]] ++;

	set<pii, greater<pii>> st;
	for(auto &[num, cnt] : mp)
		st.insert({cnt, num});

	auto updata = [&](int x, int v)-> void{
		auto it = st.find({mp[x], x});
		if(it != st.end())
			st.erase(it);
		mp[x] += v;
		st.insert({mp[x], x});
	};

	set<int> res;
	for(int i = 0; i < n; i ++){
		updata(a[i], -1);
		updata(a[i] + 1, 1);

		for(int j = 0; j < n; j ++){
			if(i == j)
				continue;
			updata(a[j], -1);
			updata(a[j] - 1, 1);

			auto it = st.begin();
			res.insert(it->second);

			updata(a[j], 1);
			updata(a[j] - 1, -1);
		}
		updata(a[i], 1);
		updata(a[i] + 1, -1);
	}
	for(auto &ans : res)
		cout << ans << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}