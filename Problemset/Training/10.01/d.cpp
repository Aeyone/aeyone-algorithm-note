#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a){
		cin >> e;
	}
	map<int, set<int>> suf;
	for(int i = 0; i < n; i ++){
		suf[a[i]].insert(i);
	}

	for(int i = 0; i < n; i ++){
		suf[a[i]].erase(i);
		int mn = inf;
		for(int j = 1; j < 4; j ++){
			if(suf[a[i] ^ j].size() > 0 && (a[i] ^ j) < a[i]){
				mn = min(mn, a[i] ^ j);
			}
		}
		if(mn != inf){
			int idx = *(-- suf[mn].end());
			suf[mn].erase(idx);
			suf[a[i]].insert(idx);
			swap(a[i], a[idx]);
		}
	}
	for(int i = 0; i < n; i ++){
		cout << a[i] << ' ';
	}
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