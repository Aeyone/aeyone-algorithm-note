#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	priority_queue<int> heap;
	int len = 0;
	for(int i = 0; i < n; i ++){
		int r = a[i].size() - 1;
		len += (r + 1);
		while(a[i][r] == '0')
			r --;
		if(a[i].size() - 1 - r > 0)
			heap.push(a[i].size() - 1 - r);
	}
	int cnt = 0;
	while(heap.size()){
		int x = heap.top();
		heap.pop();
		if(cnt % 2 == 0)
			len -= x;
		cnt ++;
	}
	if(len >= m + 1)
		cout << "Sasha" << '\n';
	else
		cout << "Anna" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}