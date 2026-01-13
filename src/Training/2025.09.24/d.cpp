#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int N = s.size();
	s = "&" + s;
	vector<array<int, 4>> v(N + 1);
	int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
	map<char, int> mp;
	mp['U'] = 0, mp['D'] = 1, mp['L'] = 2, mp['R'] = 3;

	v[0] = {};
	int x = 0, y = 0;
	for(int i = 1; i <= N; i ++){
		x = x + dx[mp[s[i]]], y = y + dy[mp[s[i]]];
		v[i] = {
			max(v[i - 1][0], x),
			min(v[i - 1][1], x),
			min(v[i - 1][2], y),
			max(v[i - 1][3], y)
		};
	}
	int l = 1, r = N, ans = -1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(v[mid][0] - v[mid][1] + 1 <= n && v[mid][3] - v[mid][2] + 1 <= m){
			ans = mid, l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	if(ans == -1){
		cout << "1 1" << '\n';
	}else{
		cout << 1 - v[ans][1] << ' ' << 1 - v[ans][2] << '\n';
	}

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}