#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int m, n;
	cin >> n >> m;
	set<i64> st;
	for(int i = 0; i < n; i ++){
		i64 x;
		cin >> x;
		st.insert(x);
	}
	i64 pos = *(st.begin());
	priority_queue<pair<i64, pair<i64, i64>>> heap;
	for(auto e : st){
		i64 d = e - pos;
		heap.push({d, {pos, e}});
		pos = e;
	}
	heap.push({0, {pos, pos}});
	i64 ans = 0;
	while(heap.size()){
		auto now = heap.top();
		heap.pop(), m --;
		if(m < 1)
			ans += now.first;
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}