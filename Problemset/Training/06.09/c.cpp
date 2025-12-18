#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	map<int, int> backup, cnt;
	vector<int> a(2 * n);
	int st = 0;
	for(int i = 0; i < 2 * n; i ++){
		cin >> a[i];
		backup[a[i]] ++;
		st = max(st, a[i]);
	}
	map<int, vector<pii>> mp;
	for(int i = 0; i < 2 * n; i ++){
		for(int j = i + 1; j < 2 * n; j ++){
			int sum = a[i] + a[j];
			int mn = min(a[i], a[j]), mx = max(a[i], a[j]);
			mp[sum].push_back({mx, mn});
		}
	}
	for(auto &[_, v] : mp)
		sort(v.begin(), v.end(), greater<pii>());
	
	vector<pii> res;
	bool ok = false;
	for(int i = 0; i < 2 * n; i ++){
		if(a[i] == st)
			continue;

		cnt = backup;
		res.clear();
		res.push_back({st, a[i]});
		cnt[a[i]] --;

		while(res.size() < n){
			int sum = res.back().first;
			if(mp.find(sum) == mp.end() || mp[sum].size() == 0)
				break;
			
			int x = -1, y = -1;
			for(auto [xx, yy] : mp[sum]){
				if(!cnt[xx] || !cnt[yy] || (xx == yy && cnt[xx] < 2))
					continue;
				x = xx, y = yy;
				break;
			}
			if(x == -1 || y == -1)
				break;

			res.push_back({x, y});
			cnt[x] --, cnt[y] --;
		}
		if(res.size() == n){
			ok = true;
			break;
		}
	}

	if(ok){
		cout << "YES" << '\n';
		cout << res[0].first + res[0].second << '\n';
		for(auto [x, y] : res)
			cout << x << " " << y << '\n';
	}else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}