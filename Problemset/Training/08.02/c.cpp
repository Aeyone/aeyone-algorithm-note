#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> a(n);
	map<pair<int, int>, pair<int, int>> mp;
	for(int i = 0; i < n; i ++){
		auto &[l, r, idx] = a[i];
		cin >> l >> r, idx = i;
		mp[{l, r}] = {l, r};
	}
	sort(a.begin(), a.end(), [](auto &a, auto & b){
		return (a[0] < b[0] ? true : (a[0] == b[0] ? (a[1] > b[1]) : false));
	});
	set<int> s;
	for(auto &[l, r, idx] : a){
		auto it = s.lower_bound(r); //>r
		if(it != s.end())
			mp[{l, r}].second = *it;
		s.insert(r);
	}
	s.clear();
	sort(a.begin(), a.end(), [](auto &a, auto & b){
		return (a[1] > b[1] ? true : (a[1] == b[1] ? (a[0] < b[0]) : false));
	});
	for(auto &[l, r, idx] : a){
		auto it = s.upper_bound(l); //>=l
		if(it != s.begin())
			mp[{l, r}].first = *(-- it);//<l
		s.insert(l);
	}
	sort(a.begin(), a.end(), [](auto &a, auto & b){
		return (a[2] < b[2]);
	});
	for(int i = 0; i < n; i ++){
		auto &[l, r, idx] = a[i];
		int L = mp[{l, r}].first, R = mp[{l, r}].second;
		cout << (R - L + 1) - (r - l + 1)<< '\n';
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