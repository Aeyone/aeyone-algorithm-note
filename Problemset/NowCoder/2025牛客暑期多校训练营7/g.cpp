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
int divide(int x){
	int cnt = 0;
	for(int i = 0; (p[i] <= x / p[i] && i < p.size()); i ++)
		while(x % p[i] == 0)
			x /= p[i], cnt ++;

	if(x > 1)
		cnt ++;
	return cnt;
}
void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	for(int i = 1; i <= n; i ++){
		if(divide(i) & 1)
			ans.push_back(i);
		if(ans.size() == n / 2)
			break;
	}
	sort(ans.begin(), ans.end());
	for(auto e : ans)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	build(1e6);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}