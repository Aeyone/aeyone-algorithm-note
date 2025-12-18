#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//大粪2
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<string> v(k);
	vector<int> L(k);
	vector<vector<int>> d(k), sum(k);
	for(int i = 0; i < k; i ++){
		cin >> L[i];
		L[i] --;
	}
	for(int i = 0; i < k; i ++){
		int l = L[i], r;
		cin >> r;
		r --;
		v[i] = s.substr(l, r - l + 1);
		d[i].resize(v[i].size() + 1, 0);
		sum[i].resize(v[i].size(), 0);
	}
	int q;
	cin >> q;
	while(q --){
		int x;
		cin >> x;
		x --;
		int idx = upper_bound(L.begin(), L.end(), x) - L.begin() - 1;
		x -= L[idx];
		int l = min(x, (int)v[idx].size() - x - 1), r = max(x, (int)v[idx].size() - x - 1);
		d[idx][l] ++, d[idx][r + 1] --;
	}
	for(int i = 0; i < k; i ++){
		sum[i][0] = d[i][0];
		for(int j = 1; j < v[i].size(); j ++){
			sum[i][j] = sum[i][j - 1] + d[i][j];
		}
		for(int j = 0; j < v[i].size() / 2; j ++){
			if(sum[i][j] & 1){
				swap(v[i][j], v[i][v[i].size() - j - 1]);
			}
		}
	}
	for(auto e : v)
		cout << e;
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