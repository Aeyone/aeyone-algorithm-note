#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
map<int, bool> mp;

void solve() {
	int n;
	cin >> n;
	if(mp[n]){
		cout << -1 << '\n';
		return;
	}
	vector<int> res(n);

	queue<int> q;
	for(int i = 0; i < n; i ++){
		res[i] = i + 1;
		if(mp[i + 1])
			q.push(i);
	}
	while(q.size()){
		int x = q.front();
		q.pop();
		swap(res[x], res[x + 1]);
	}

	for(auto e : res){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	for(int i = 1; i <= 1e6; i ++){
		i64 ans = (i64)(i + 1) * i / 2;
		if((double)sqrt(ans) == (int)sqrt(ans))
			mp[i] = true;
	}

	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}