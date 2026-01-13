#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//经典dp
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	map<int, int> len;
	map<int, set<int>> st;
	for(int i = 1; i <= n; i ++){
		st[a[i]].insert(i);
		len[a[i]] = max(len[a[i]], len[a[i] - 1] + 1);
	}
	int ans = -INF, num = -1;
	for(int i = 1; i <= n; i ++){
		int x = len[a[i]];
		if(x > ans){
			ans = x, num = a[i];			
		}
	}
	cout << ans << '\n';
	vector<int> res;
	int idx = INF;
	for(int i = num; i > num - ans; i --){
		idx = *(--st[i].lower_bound(idx));//贪心找最高位即可
		res.push_back(idx);
	}
	reverse(res.begin(), res.end());
	for(auto e : res){
		cout << e << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}