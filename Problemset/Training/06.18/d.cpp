#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef pair<int, int> pii;

void solve() {
	int n;
	cin >> n;
	priority_queue<pii> q;
	vector<int> a(n);
	q.push({n, 0});
	int cnt = 1;
	while(q.size()){
		auto now = q.top();
		q.pop();
		int siz = now.first, l = - now.second;

		int mid = l + (siz - 1) / 2;
		// cout << siz << ' ' << l << ' ' << mid << '\n';
		a[mid] = cnt ++;
		if(siz == 1)
			continue;
		if(siz > 2)
			q.push({mid - l, - l});

		if(siz & 1)
			q.push({mid - l, - (mid + 1)});
		else
			q.push({mid - l + 1, - (mid + 1)});
	}
	for(auto e : a)
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